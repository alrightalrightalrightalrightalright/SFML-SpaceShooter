#include "NesneYonetici.hpp"
#include "Onbellek.hpp"
#include <iostream>


template <typename C, typename T>
void vektordenNesneSil(C data, T& source)
{
	source.erase(std::remove(source.begin(),
		source.end(), data), source.end());
	delete data;
}



//t�m nesneleri hareket ettir.
//HER FRAMEDE �A�RILAMSI GEREK�R
void NesneYonetici::hareketEttir() {

	
	for (auto dusmangemisi : m_dusmanlar)
	{
		dusmangemisi->hareketEt();
		dusmangemisi->m_cerceveIndex++;

		for (auto siradakiMermi : dusmangemisi->m_mermiler)
		{
			siradakiMermi->hareketEt();

			if (siradakiMermi->getSpriteBounds().intersects(m_oyuncu->getSpriteBounds())) {
				std::cout << "MAL YANDIN" << std::endl;
				Efekt* patlama = new Efekt(*Onbellek::getInstance().m_patlamaEfekt);
				patlama->_rastgelelikVer();//
				m_efektler.push_back(patlama);

				//genellikle yukardan �arpaca�� farzedilerek 10 birim a�a��da patlat�l�yor
				patlama->setKonum(siradakiMermi->getCenter()+sf::Vector2f(0,10));

				vektordenNesneSil(siradakiMermi, dusmangemisi->m_mermiler);
			}
			/*
			auto konum = m_top.getKonum();
			auto boyut = m_pencere.pencereGetir().getSize();

			float angle = atan2(konum.y, konum.x);


			//pencereye(kenarlara) �arpma kontrol:
			/*�zetle pencere kenarlar� + duvarlar�n boyutu kadar yak�nl��a �arpma kontorl ediliyor ve ona
			g�re top sekiyor. yani her bir duvara tek tek �arpt� m� kontr�l� yap�lm�yor performans gere�i.
			if (konum.x + m_ornekDuvar.getBoyut().x <= m_top.m_sprite.getGlobalBounds().width) { carpis(); }//sol
			else if (konum.y + m_ornekDuvar.getBoyut().y <= m_top.m_sprite.getGlobalBounds().height) { carpis(); }//�st
			else if (konum.x + 2*m_ornekDuvar.getBoyut().x >= boyut.x) {
				carpis(); }//sa�
			else if (konum.y +2*m_ornekDuvar.getBoyut().y >= boyut.y) { carpis(); }//alt

			//pade �arpma kontorl
			if (m_top.m_sprite.getGlobalBounds().intersects(m_pad.getSpriteBounds()))
				carpis();

				*/









		}
	}

	m_oyuncu->hareketEt();
	m_oyuncu->m_cerceveIndex++;

	for (auto siradaki : m_oyuncu->m_mermiler)
	{
		siradaki->hareketEt();
	}


}


 
void NesneYonetici::ciz(sf::RenderWindow& pencere)
{
	//D��MANLAR
	for (auto dusmangemisi : m_dusmanlar)
	{
		dusmangemisi->ciz(pencere);

		for (auto siradakiMermi : dusmangemisi->m_mermiler)
		{
			//siradakiMermi->ciz(pencere);
			//MERM� TA�TIYSA S�LLLLLLLLLL
			if (!siradakiMermi->haritaDisindaMi())
				siradakiMermi->ciz(pencere);
			else {
				std::cout << "DUSMNAmermi silindi, mrm count:" << dusmangemisi->m_mermiler.size() << std::endl;
				dusmangemisi->m_mermiler.erase(std::remove(dusmangemisi->m_mermiler.begin(),
					dusmangemisi->m_mermiler.end(), siradakiMermi), dusmangemisi->m_mermiler.end());
				delete siradakiMermi;
			}
		}
	}

	//OYUNCU
	m_oyuncu->ciz(pencere);
	for (auto siradaki : m_oyuncu->m_mermiler)
	{
		//MERM� TA�TIYSA S�LLLLLLLLLL
		if (!siradaki->haritaDisindaMi())
			siradaki->ciz(pencere);
		else {
			std::cout << "mermi silindi, mrm count:" << m_oyuncu->m_mermiler.size() << std::endl;
			m_oyuncu->m_mermiler.erase(std::remove(m_oyuncu->m_mermiler.begin(),
				m_oyuncu->m_mermiler.end(), siradaki), m_oyuncu->m_mermiler.end());
			delete siradaki;
		}
	}

	//EFEKTLER
	for (auto siradaki: m_efektler)
	{
		if (!siradaki->m_efektBitti)
			siradaki->ciz(pencere);
		else {
			m_efektler.erase(std::remove(m_efektler.begin(),
				m_efektler.end(), siradaki), m_efektler.end());
			delete siradaki;
		}
	}

	return;

}
