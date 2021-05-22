#pragma once

#include "Pencere.hpp"
#include "Spaceship.hpp"
#include "Mermi.hpp"
#include "DusmanUcak.hpp"
#include "Efekt.hpp"
#include "Spacebomb.hpp"
#include "Spacemine.hpp"
#include "Spacestation.hpp"
#include <list>
//tüm oyun için nesneleri yöneten sýnýf. hareket, çarpýþma kontrolu vs gibi tüm kontrol mekanizmalarýný yürütür.

/*oyun içi tüm nesneler buradan yürütülür. bir patlama efekti veya oyundaki hareket eden bir mermi
* bu sýnýf üzerinden hareket ettirilir, baþlatýlmasý ve silinmesi gerçekleþir.
bir nevi oyun motoru da denilebilir. * 
*/

class NesneYonetici
{
private:
	NesneYonetici() {}

	void _mermiCarpmaKontrol();
	template <typename T, typename C>
	bool _oyuncuyaCarpmaKontrol(T varlik, C& varlikDepo);

	template<typename T, typename C, typename V, typename W>
	bool _varliklarCarpismaKontrol(T varlik1,C varlik2, V& varlik1Depo, W& varlik2Depo);

public:
	static NesneYonetici& getInstance() {
		static NesneYonetici instance;
		return instance;
	}

	std::vector<Mermi*>				m_mermiler;//dusman mermisi ile oyuncu farký mermide tutuluyor. ikinci bi düþman mermi vektörüne gerke yok
	std::vector<Spacemine*>			m_mines;
	std::vector<Spacebomb*>			m_bombs;
	std::vector<Spacestation*>		m_stations;
	std::vector<Efekt*>				m_efektler;
	std::vector<DusmanUcak*>		m_dusmanlar;//mermiler de burdan yönetilcek
	Spaceship	*					m_oyuncu;

	void nesneleriHareketEttir();
	void nesneleriCiz(sf::RenderWindow& pencere);

};

