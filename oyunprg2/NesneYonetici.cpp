#include "NesneYonetici.hpp"
#include "Onbellek.hpp"
#include <iostream>

/*
OYUNCU MERM�LER�NDE �K�NC� FORA break; EKLE
S�LME ���N NESNEY�NET�C�DE S�L�NECEKLER TUTULUP HER FRAME SONU BUNLAR S�L�NEB�L�R?
*/
//mermilerin �arpma olaylar� ve hareket ettirilmesi


/*Varl�k(dusman ucak, bomba, may�n...) oyuncuya �arp�yor mu kontrol.
e�er �arp�yorsa varl�k patlamayla yok oluyor, oyuncu hasar al�yor.*/
template <typename T, typename C>
bool NesneYonetici::_oyuncuyaCarpmaKontrol(T varlik, C& varlikDepo) {
	if (varlik->getSpriteBounds().intersects(m_oyuncu->getSpriteBounds())) {
		std::cout << "YANDIN xd" << std::endl;
		Efekt* patlama = new Efekt(*Onbellek::getInstance().m_patlamaEfekt);
		patlama->_rastgelelikVer();
		m_efektler.push_back(patlama);

		patlama->setKonum((varlik)->getCenter());
		vektordenNesneSil(varlik, varlikDepo);
		m_oyuncu->hasarAl();
		return true;
	}
	return false;
}

/*�ki varl���n �arp��mas�n� kontrol eder. �arp��ma var ise
iki varl�k yok olur, ilk parametredeki varl�k �zerinde
patlama efekti olu�ur.*/
template <typename T, typename C, typename V, typename W>
bool NesneYonetici::_varliklarCarpismaKontrol(T varlik1, C varlik2, V& varlik1Depo, W& varlik2Depo) {

	if ((varlik1)->getSpriteBounds().intersects(varlik2->getSpriteBounds())) {
		Efekt* patlama = new Efekt(*Onbellek::getInstance().m_patlamaEfekt);
		patlama->_rastgelelikVer();
		m_efektler.push_back(patlama);

		patlama->setKonum((varlik1)->getCenter());

		vektordenNesneSil(varlik1, varlik1Depo);
		vektordenNesneSil(varlik2, varlik2Depo);
		return true;
	}
	return false;
}


void NesneYonetici::_mermiCarpmaKontrol() {
	for (auto siradakiMermi : m_mermiler) {

		if ((siradakiMermi)->haritaDisindaMi()) {
			vektordenNesneSil((siradakiMermi), m_mermiler);
			break;
		}
		(siradakiMermi)->hareketEt();


		//oyuncu mermileri kontrol
		if ((siradakiMermi)->m_kaynakGemi == GEMI_TURU::oyuncuUcak) {
			for (auto dusmangemisi : m_dusmanlar)
			{
				if (_varliklarCarpismaKontrol(siradakiMermi, dusmangemisi
					, m_mermiler, m_dusmanlar))
					break;
			}
			for (auto varlik : m_bombs)
			{
				if (_varliklarCarpismaKontrol(siradakiMermi, varlik
					, m_mermiler, m_bombs))
					break;
			}
			for (auto varlik : m_stations)
			{
				if (_varliklarCarpismaKontrol(siradakiMermi, varlik
					, m_mermiler, m_stations))
					break;
			}
			for (auto varlik : m_mines)
			{
				if (_varliklarCarpismaKontrol(siradakiMermi, varlik
					, m_mermiler, m_mines))
					break;
			}

		}

		//d��man mermisi kontrol
		else {
			if (_oyuncuyaCarpmaKontrol(siradakiMermi, m_mermiler)) 
				break;
		}
		if (m_mermiler.size() == 0)break;
	}
}





//t�m nesneleri hareket ettir. VE BAZI KONTROLLER.
//TODO: hareket ile kontrolleri ay�r.
//HER FRAMEDE �A�RILAMSI GEREK�R
void NesneYonetici::nesneleriHareketEttir() {
	//OYUNCU
	m_oyuncu->hareketEt();
	m_oyuncu->m_cerceveIndex++;


	/*Iterator invalidation hatas�:
	range based d�ng�lerle(itr:collection) yap�lan hareketler sonucu haritadan ta�an
	varl�k bulundu�u iterasyonda siliniyor. bunun sonucu i�inde bulunulan d�ng�de
	silinen her eleman i�in son eleman tekrar d�ng�ye giriyor. vekt�rlerin eksik
	y�n� olan bu sorunu ��zmek i�in tersten d�ng� kullan�l�yor.*/

	/*her �er�evede bir adet d��man silindikten sonra d�ng� k�r�larak bir yandan
	* performans elde ediliyorken di�er yandan gelecekte baz� tutars�zl�klar olabilir.
	*/

	//D��MANLAR
	for (auto siradaki : m_dusmanlar) {
		//ta�t�ysa
		if (siradaki->getKonum().y >= 100 && siradaki->haritaDisindaMi()) {
			vektordenNesneSil(siradaki, m_dusmanlar);
			break;
		}
		siradaki->hareketEt();
		if (_oyuncuyaCarpmaKontrol(siradaki, m_dusmanlar)) break;
	}


	//BOMBALAR
	for (auto siradaki : m_bombs) {
		if (siradaki->getKonum().y >= 100 && siradaki->haritaDisindaMi()) {
			vektordenNesneSil(siradaki, m_bombs);
			break;
		}
		siradaki->hareketEt();
		if (_oyuncuyaCarpmaKontrol(siradaki, m_bombs))break;
	}


	//MAYINLAR
	for (auto siradaki : m_mines) {
		if (siradaki->getKonum().y >= 100 && siradaki->haritaDisindaMi()) {
			vektordenNesneSil(siradaki, m_mines);
			break;
		}
		siradaki->hareketEt();
		if (_oyuncuyaCarpmaKontrol(siradaki, m_mines))break;
	}


	//�STASYONLAR
	for (auto siradaki : m_stations) {
		if (siradaki->getKonum().y >= 100 && siradaki->haritaDisindaMi()) {
			vektordenNesneSil(siradaki, m_stations);
			break;
		}
		siradaki->hareketEt();
		if (_oyuncuyaCarpmaKontrol(siradaki, m_stations))break;
	}

	//EFEKTLER
	for (auto siradaki : m_efektler)
	{
		if (siradaki->m_efektBitti){
			vektordenNesneSil(siradaki, m_efektler);
			break;
		}
	}


	//MERM�LER ve mermi �arp��mas�, performans i�in ek d�ng� gerek yok.
	_mermiCarpmaKontrol();
}

void NesneYonetici::nesneleriCiz(sf::RenderWindow& pencere)
{
	//OYUNCU
	m_oyuncu->ciz(pencere);

	//D��MANLAR
	for (auto dusmangemisi : m_dusmanlar) {
		(dusmangemisi)->ciz(pencere);
	}


	//MERM�LER
	for (auto siradakiMermi : m_mermiler) {
		siradakiMermi->ciz(pencere);
	}

	//BOMBALAR
	for (auto siradaki : m_bombs)
	{
		siradaki->ciz(pencere);
	}

	//MAYINLAR
	for (auto siradaki : m_mines)
	{
		siradaki->ciz(pencere);
	}

	//�STASYONLAR
	for (auto siradaki : m_stations)
	{
		siradaki->ciz(pencere);
	}

	//EFEKTLER
	for (auto siradaki : m_efektler)
	{
		siradaki->ciz(pencere);
	}

	return;
}
