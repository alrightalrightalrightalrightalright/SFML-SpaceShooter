#include "NesneYonetici.hpp"
#include "Onbellek.hpp"
#include <iostream>




//mermilerin çarpma olaylarý ve hareket ettirilmesi
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

		//düþman mermisi kontrol
		else {
			if ((*siradakiMermi)->getSpriteBounds().intersects(m_oyuncu->getSpriteBounds())) {
				std::cout << "MAL YANDIN" << std::endl;
				Efekt* patlama = new Efekt(*Onbellek::getInstance().m_patlamaEfekt);
				patlama->_rastgelelikVer();//
				m_efektler.push_back(patlama);

				//genellikle yukardan çarpacaðý farzedilerek 10 birim aþaðýda patlatýlýyor
				patlama->setKonum((*siradakiMermi)->getCenter() + sf::Vector2f(0, 10));

				vektordenNesneSil((*siradakiMermi), m_mermiler);
			}
		}

	}
}

//tüm nesneleri hareket ettir.
//HER FRAMEDE ÇAÐRILAMSI GEREKÝR
void NesneYonetici::nesneleriHareketEttir() {
	//OYUNCU
	m_oyuncu->hareketEt();
	m_oyuncu->m_cerceveIndex++;


	/*range based döngülerle(itr:collection) yapýlan hareketler sonucu haritadan taþan
	varlýk bulunduðu iterasyonda siliniyor. bunun sonucu içinde bulunulan döngüde
	silinen her eleman için son eleman tekrar döngüye giriyor. vektörlerin eksik 
	yönü olan bu sorunu çözmek için tersten döngü kullanýlýyor.(Iterator invalidation)*/

	//DÜÞMANLAR
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

	//ÝSTASYONLAR
	for (auto siradaki = m_stations.rbegin(); siradaki != m_stations.rend(); ++siradaki)
	{
		(*siradaki)->hareketEt();
	}

	/*for (auto siradakiMermi = m_mermiler.rbegin(); siradakiMermi != m_mermiler.rend(); ++siradakiMermi) {
		(*siradakiMermi)->hareketEt();
	}*/
	//MERMÝLER ve mermi çarpýþmasý, performans için ek döngü gerek yok.
	_mermiCarpmaKontrol();
}

void NesneYonetici::nesneleriCiz(sf::RenderWindow& pencere)
{
	//OYUNCU
	m_oyuncu->ciz(pencere);

	//DÜÞMANLAR
	for (auto dusmangemisi : m_dusmanlar)
	{
		dusmangemisi->ciz(pencere);
	}

	//MERMÝLER
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

	//ÝSTASYONLAR
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
