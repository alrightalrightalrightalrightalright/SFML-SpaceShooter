#pragma once
#include "Animatable.hpp"
#include "Mermi.hpp"
/*---------yarasa uçak-----------
* animasyon dosya sayýsý: 4
* dosya konumu: ..+ "uzay\\yarasaucak\\"
* texture bölgesi: 65, 59, 376, 393 
* 
* -----------küçük ucak---------------
* animasyon dosya sayýsý: 5
* dosya konumu: ..+ "uzay\\smallship\\"
* texture bölgesi: 71, 29, 481, 520
*/
enum class  GEMI_TURU {kucukUcak,yarasaUcak};

class DusmanUcak:public Animatable
{

public:

	//init kolaylýðý için hazýr ayarlar:
	static DusmanUcak*  YarasaUcak(sf::Vector2f konum = sf::Vector2f(120, 50)) {
		return new DusmanUcak(konum, 0.9f,
			2, GEMI_TURU::yarasaUcak, 4, "uzay\\yarasaucak\\",
			sf::IntRect(65, 59, 376, 393));
	}	
	static DusmanUcak*  KucukUcak(sf::Vector2f konum = sf::Vector2f(120, 50)) {
		return new DusmanUcak(konum,  0.2f,
			 1, GEMI_TURU::kucukUcak,  5,  "uzay\\smallship\\",
			sf::IntRect(71, 29, 481, 520), 350);
	}

	DusmanUcak(sf::Vector2f konum= sf::Vector2f(120, 50), float ucakHizi = 0.2f,
		float mermiHizi=1, GEMI_TURU tur= GEMI_TURU::kucukUcak, int animSayisi=5,sf::String animLoc= "uzay\\smallship\\",
		sf::IntRect animArea= sf::IntRect(71, 29, 481, 520), int atesMaxCD=350);

	void atesEt();
	void HaritadanCikti() override;
	void hareketEt();

	std::vector<Mermi*>		m_mermiler;
	int						m_cerceveIndex;
private:
	Mermi					m_mermi;
	int						m_atesEtmeCD;//random için gerekli
	int						m_atesMaxCD;
	float						m_mermiHizi;//y ekseninde
	float						m_ucakHizi;//y ekseninde
	GEMI_TURU				m_gemiTuru;
};

