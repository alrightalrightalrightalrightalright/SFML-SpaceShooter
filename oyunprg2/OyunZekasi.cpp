#include "OyunZekasi.hpp"
#include "NesneYonetici.hpp"
#include "DusmanUcak.hpp"
#include "Onbellek.hpp"

OyunZekasi::OyunZekasi()
{
	m_maxDusmanSayisi = 0;
	m_spawnCD = 600;
	m_cerceveSayac = 0;
}

//her frame çalýþtýrýlmasý lazým, döngü gibi
void OyunZekasi::Kontrol(sf::RenderWindow& window)
{	
	auto pencereBoyut = window.getSize();

	int dusmanSayisi = NesneYonetici::getInstance().m_dusmanlar.size();//performans kaybý?

	if (dusmanSayisi < m_maxDusmanSayisi && m_spawnCD >= m_cerceveSayac) {
		auto spawnKonum = sf::Vector2f(rand()%pencereBoyut.x-50, -100);//mermi taþmaya deðmemeli.
		DusmanKoy(spawnKonum);
		m_cerceveSayac = 0;
	}

	m_cerceveSayac++;
}

void OyunZekasi::DusmanKoy(sf:: Vector2f konum)
{
	Onbellek& onbellek = Onbellek::getInstance(); 
	DusmanUcak *dusman = rand() % 2 == 0 ?
		new DusmanUcak(*onbellek.m_dusmanYarasaUcak) : new DusmanUcak(*onbellek.m_dusmanKucukUcak);
	dusman->setKonum(konum);
	NesneYonetici::getInstance().m_dusmanlar.push_back(dusman);
}
