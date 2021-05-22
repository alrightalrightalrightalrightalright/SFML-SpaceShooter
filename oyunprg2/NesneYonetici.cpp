#include "NesneYonetici.hpp"
#include "Onbellek.hpp"
#include <iostream>

/*
OYUNCU MERMÝLERÝNDE ÝKÝNCÝ FORA break; EKLE
SÝLME ÝÇÝN NESNEYÖNETÝCÝDE SÝLÝNECEKLER TUTULUP HER FRAME SONU BUNLAR SÝLÝNEBÝLÝR?
*/
//mermilerin çarpma olaylarý ve hareket ettirilmesi


/*Varlýk(dusman ucak, bomba, mayýn...) oyuncuya çarpýyor mu kontrol.
eðer çarpýyorsa varlýk patlamayla yok oluyor, oyuncu hasar alýyor.*/
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

/*Ýki varlýðýn çarpýþmasýný kontrol eder. Çarpýþma var ise
iki varlýk yok olur, ilk parametredeki varlýk üzerinde
patlama efekti oluþur.*/
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

		//düþman mermisi kontrol
		else {
			if (_oyuncuyaCarpmaKontrol(siradakiMermi, m_mermiler)) 
				break;
		}
		if (m_mermiler.size() == 0)break;
	}
}





//tüm nesneleri hareket ettir. VE BAZI KONTROLLER.
//TODO: hareket ile kontrolleri ayýr.
//HER FRAMEDE ÇAÐRILAMSI GEREKÝR
void NesneYonetici::nesneleriHareketEttir() {
	//OYUNCU
	m_oyuncu->hareketEt();
	m_oyuncu->m_cerceveIndex++;


	/*Iterator invalidation hatasý:
	range based döngülerle(itr:collection) yapýlan hareketler sonucu haritadan taþan
	varlýk bulunduðu iterasyonda siliniyor. bunun sonucu içinde bulunulan döngüde
	silinen her eleman için son eleman tekrar döngüye giriyor. vektörlerin eksik
	yönü olan bu sorunu çözmek için tersten döngü kullanýlýyor.*/

	/*her çerçevede bir adet düþman silindikten sonra döngü kýrýlarak bir yandan
	* performans elde ediliyorken diðer yandan gelecekte bazý tutarsýzlýklar olabilir.
	*/

	//DÜÞMANLAR
	for (auto siradaki : m_dusmanlar) {
		//taþtýysa
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


	//ÝSTASYONLAR
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


	//MERMÝLER ve mermi çarpýþmasý, performans için ek döngü gerek yok.
	_mermiCarpmaKontrol();
}

void NesneYonetici::nesneleriCiz(sf::RenderWindow& pencere)
{
	//OYUNCU
	m_oyuncu->ciz(pencere);

	//DÜÞMANLAR
	for (auto dusmangemisi : m_dusmanlar) {
		(dusmangemisi)->ciz(pencere);
	}


	//MERMÝLER
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

	//ÝSTASYONLAR
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
