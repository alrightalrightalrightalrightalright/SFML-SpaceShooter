#include "NesneYonetici.hpp"
#include "Onbellek.hpp"
#include <iostream>




//mermilerin �arpma olaylar� ve hareket ettirilmesi
void NesneYonetici::_mermiCarpmaKontrol() {
	for (auto siradakiMermi = m_mermiler.rbegin(); siradakiMermi != m_mermiler.rend(); ++siradakiMermi) {
		if ((*siradakiMermi)->haritaDisindaMi()) {
			vektordenNesneSil((*siradakiMermi), m_mermiler);
			continue;
		}
		else
			(*siradakiMermi)->hareketEt();

		//oyuncu mermileri kontrol
		if ((*siradakiMermi)->m_kaynakGemi == GEMI_TURU::oyuncuUcak) {
			for (auto dusmangemisi : m_dusmanlar)
			{
				if ((*siradakiMermi)->getSpriteBounds().intersects(dusmangemisi->getSpriteBounds())) {
					Efekt* patlama = new Efekt(*Onbellek::getInstance().m_patlamaEfekt);
					patlama->_rastgelelikVer();
					m_efektler.push_back(patlama);

					patlama->setKonum((*siradakiMermi)->getCenter() + sf::Vector2f(0, -15));

					vektordenNesneSil((*siradakiMermi), m_mermiler);
					vektordenNesneSil(dusmangemisi, m_dusmanlar);
				}
			}

		}

		//d��man mermisi kontrol
		else {
			if ((*siradakiMermi)->getSpriteBounds().intersects(m_oyuncu->getSpriteBounds())) {
				std::cout << "MAL YANDIN" << std::endl;
				Efekt* patlama = new Efekt(*Onbellek::getInstance().m_patlamaEfekt);
				patlama->_rastgelelikVer();//
				m_efektler.push_back(patlama);

				//genellikle yukardan �arpaca�� farzedilerek 10 birim a�a��da patlat�l�yor
				patlama->setKonum((*siradakiMermi)->getCenter() + sf::Vector2f(0, 10));

				vektordenNesneSil((*siradakiMermi), m_mermiler);
			}
		}

	}
}

//t�m nesneleri hareket ettir.
//HER FRAMEDE �A�RILAMSI GEREK�R
void NesneYonetici::nesneleriHareketEttir() {
	//OYUNCU
	m_oyuncu->hareketEt();
	m_oyuncu->m_cerceveIndex++;


	/*range based d�ng�lerle(itr:collection) yap�lan hareketler sonucu haritadan ta�an
	varl�k bulundu�u iterasyonda siliniyor. bunun sonucu i�inde bulunulan d�ng�de
	silinen her eleman i�in son eleman tekrar d�ng�ye giriyor. vekt�rlerin eksik 
	y�n� olan bu sorunu ��zmek i�in tersten d�ng� kullan�l�yor.(Iterator invalidation)*/

	//D��MANLAR
	for (auto siradaki = m_dusmanlar.rbegin(); siradaki != m_dusmanlar.rend(); ++siradaki)
	{
		(*siradaki)->hareketEt();
		(*siradaki)->m_cerceveIndex++;
	}


	//BOMBALAR
	for (auto siradaki = m_bombs.rbegin(); siradaki != m_bombs.rend(); ++siradaki)
	{
		(*siradaki)->hareketEt();
	}

	//MAYINLAR
	for (auto siradaki = m_mines.rbegin(); siradaki != m_mines.rend(); ++siradaki)
	{
		(*siradaki)->hareketEt();
	}

	//�STASYONLAR
	for (auto siradaki = m_stations.rbegin(); siradaki != m_stations.rend(); ++siradaki)
	{
		(*siradaki)->hareketEt();
	}

	/*for (auto siradakiMermi = m_mermiler.rbegin(); siradakiMermi != m_mermiler.rend(); ++siradakiMermi) {
		(*siradakiMermi)->hareketEt();
	}*/
	//MERM�LER ve mermi �arp��mas�, performans i�in ek d�ng� gerek yok.
	_mermiCarpmaKontrol();
}

void NesneYonetici::nesneleriCiz(sf::RenderWindow& pencere)
{
	//OYUNCU
	m_oyuncu->ciz(pencere);

	//D��MANLAR
	for (auto dusmangemisi : m_dusmanlar)
	{
		dusmangemisi->ciz(pencere);
	}

	//MERM�LER
	for (auto siradaki : m_mermiler)
	{
		siradaki->ciz(pencere);
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
		if (!siradaki->m_efektBitti)
			siradaki->ciz(pencere);
		else {
			vektordenNesneSil(siradaki, m_efektler);
		}
	}

	return;
}
