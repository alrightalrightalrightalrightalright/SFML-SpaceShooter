#include "OyunZekasi.hpp"
#include "NesneYonetici.hpp"
#include "Onbellek.hpp"

OyunZekasi::OyunZekasi()
{
	m_maxDusmanSayisi = 15;//her d��man cinsinden 5'er adet.
	m_maxIstasyonSayisi = 5;
	m_maxBombaSayisi = 9;
	m_maxMayinSayisi = 6;

	m_spawnCD = 120;
	m_cerceveSayac = m_spawnCD;
}

//her frame �al��t�r�lmas� laz�m, d�ng� gibi
void OyunZekasi::Kontrol(sf::RenderWindow& window)
{

	//s�rekli spawnlan�rsa bir s�re sonra dalga dalga d��manlar geliyor. tats�z olur.
	if (m_cerceveSayac >= m_spawnCD) {

		NesneYonetici& yonetici = NesneYonetici::getInstance();
		//performans kayb�?
		int dusmanGemiSayisi = yonetici.m_dusmanlar.size();
		int istasyonSayisi = yonetici.m_stations.size();
		int bombaSayisi = yonetici.m_bombs.size();
		int mayinSayisi = yonetici.m_mines.size();
		
		Onbellek& onbellek = Onbellek::getInstance();

		auto pencereBoyut = window.getSize();

		if (dusmanGemiSayisi < m_maxDusmanSayisi) {
			auto spawnKonum = sf::Vector2f(rand() % pencereBoyut.x - 50, -100);//mermi ta�maya de�memeli.
			DusmanUcak* dusman = rand() % 2 == 0 ?
				new DusmanUcak(*onbellek.m_dusmanYarasaUcak) : new DusmanUcak(*onbellek.m_dusmanKucukUcak);
			dusman->setKonum(spawnKonum);
			yonetici.m_dusmanlar.push_back(dusman);
		}

		if (bombaSayisi < m_maxBombaSayisi) {
			auto spawnKonum = sf::Vector2f(rand() % pencereBoyut.x - 50, -100);//mermi ta�maya de�memeli.
			Spacebomb* bomba = new Spacebomb(*onbellek.m_spaceBomb);
			bomba->setKonum(spawnKonum);//TODO: konumlar� t�m�n� ayn� yerden, merkezden y�net
			yonetici.m_bombs.push_back(bomba);
		}
		if (istasyonSayisi < m_maxIstasyonSayisi) {
			auto spawnKonum = sf::Vector2f(rand() % pencereBoyut.x - 50, -100);//mermi ta�maya de�memeli.
			Spacestation* istasyon = new Spacestation(*onbellek.m_spaceStation);
			istasyon->setKonum(spawnKonum);
			yonetici.m_stations.push_back(istasyon);
		}
		if (mayinSayisi < m_maxMayinSayisi) {
			auto spawnKonum = sf::Vector2f(rand() % pencereBoyut.x - 50, -100);//mermi ta�maya de�memeli.
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
