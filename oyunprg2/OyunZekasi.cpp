#include "OyunZekasi.hpp"
#include "NesneYonetici.hpp"
#include "Onbellek.hpp"

OyunZekasi::OyunZekasi()
{
	m_maxDusmanSayisi = 15;//her düþman cinsinden 5'er adet.
	m_maxIstasyonSayisi = 5;
	m_maxBombaSayisi = 9;
	m_maxMayinSayisi = 6;

	m_spawnCD = 120;
	m_cerceveSayac = m_spawnCD;
}

//her frame çalýþtýrýlmasý lazým, döngü gibi
void OyunZekasi::Kontrol(sf::RenderWindow& window)
{

	//sürekli spawnlanýrsa bir süre sonra dalga dalga düþmanlar geliyor. tatsýz olur.
	if (m_cerceveSayac >= m_spawnCD) {

		NesneYonetici& yonetici = NesneYonetici::getInstance();
		//performans kaybý?
		int dusmanGemiSayisi = yonetici.m_dusmanlar.size();
		int istasyonSayisi = yonetici.m_stations.size();
		int bombaSayisi = yonetici.m_bombs.size();
		int mayinSayisi = yonetici.m_mines.size();
		
		Onbellek& onbellek = Onbellek::getInstance();

		auto pencereBoyut = window.getSize();

		if (dusmanGemiSayisi < m_maxDusmanSayisi) {
			auto spawnKonum = sf::Vector2f(rand() % pencereBoyut.x - 50, -100);//mermi taþmaya deðmemeli.
			DusmanUcak* dusman = rand() % 2 == 0 ?
				new DusmanUcak(*onbellek.m_dusmanYarasaUcak) : new DusmanUcak(*onbellek.m_dusmanKucukUcak);
			dusman->setKonum(spawnKonum);
			yonetici.m_dusmanlar.push_back(dusman);
		}

		if (bombaSayisi < m_maxBombaSayisi) {
			auto spawnKonum = sf::Vector2f(rand() % pencereBoyut.x - 50, -100);//mermi taþmaya deðmemeli.
			Spacebomb* bomba = new Spacebomb(*onbellek.m_spaceBomb);
			bomba->setKonum(spawnKonum);//TODO: konumlarý tümünü ayný yerden, merkezden yönet
			yonetici.m_bombs.push_back(bomba);
		}
		if (istasyonSayisi < m_maxIstasyonSayisi) {
			auto spawnKonum = sf::Vector2f(rand() % pencereBoyut.x - 50, -100);//mermi taþmaya deðmemeli.
			Spacestation* istasyon = new Spacestation(*onbellek.m_spaceStation);
			istasyon->setKonum(spawnKonum);
			yonetici.m_stations.push_back(istasyon);
		}
		if (mayinSayisi < m_maxMayinSayisi) {
			auto spawnKonum = sf::Vector2f(rand() % pencereBoyut.x - 50, -100);//mermi taþmaya deðmemeli.
			Spacemine* mine = new Spacemine(*onbellek.m_spaceMine);
			mine->setKonum(spawnKonum);
			yonetici.m_mines.push_back(mine);
		}
		
		m_cerceveSayac = 0;
		std::cout << "dusman(lar) spawnmlandi" << std::endl;
	}

	m_cerceveSayac++;
}

void OyunZekasi::DusmanKoy(sf::Vector2f konum)
{
	Onbellek& onbellek = Onbellek::getInstance();
	DusmanUcak* dusman = rand() % 2 == 0 ?
		new DusmanUcak(*onbellek.m_dusmanYarasaUcak) : new DusmanUcak(*onbellek.m_dusmanKucukUcak);
	dusman->setKonum(konum);
	NesneYonetici::getInstance().m_dusmanlar.push_back(dusman);
}
