#pragma once

#include "Pencere.hpp"
#include "Spaceship.hpp"
#include "Mermi.hpp"
#include "DusmanUcak.hpp"
#include "Efekt.hpp"
#include "Spacebomb.hpp"
#include "Spacemine.hpp"
#include "Spacestation.hpp"
//tüm oyun için nesneleri yöneten sýnýf. hareket, çarpýþma kontrolu vs gibi tüm kontrol mekanizmalarýný yürütür.

/*oyun içi tüm nesneler buradan yürütülür. bir patlama efekti veya oyundaki hareket eden bir mermi
* bu sýnýf üzerinden hareket ettirilir, baþlatýlmasý ve silinmesi gerçekleþir.* 
*/

class NesneYonetici
{
private:
	NesneYonetici() {
	}

public:
	static NesneYonetici& getInstance() {
		static NesneYonetici instance;
		return instance;
	}
	//TODO: mermilerin gemide deðil de burada tutulmasý daha mantýklý.

	std::vector<Mermi*>				m_mermiler;//dusman mermisi ile oyuncu farký mermide tutuluyor. ikinci bi düþman mermi vektörüne gerke yok
	std::vector<Spacemine*>			m_mines;
	std::vector<Spacebomb*>			m_bombs;
	std::vector<Spacestation*>		m_stations;
	std::vector<Efekt*>				m_efektler;
	std::vector<DusmanUcak*>		m_dusmanlar;//mermiler de burdan yönetilcek
	Spaceship	*					m_oyuncu;

	void _mermiCarpmaKontrol();

	void nesneleriHareketEttir();
	void nesneleriCiz(sf::RenderWindow& pencere);

};

