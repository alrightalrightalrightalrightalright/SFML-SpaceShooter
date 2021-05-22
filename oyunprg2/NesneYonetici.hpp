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
//t�m oyun i�in nesneleri y�neten s�n�f. hareket, �arp��ma kontrolu vs gibi t�m kontrol mekanizmalar�n� y�r�t�r.

/*oyun i�i t�m nesneler buradan y�r�t�l�r. bir patlama efekti veya oyundaki hareket eden bir mermi
* bu s�n�f �zerinden hareket ettirilir, ba�lat�lmas� ve silinmesi ger�ekle�ir.
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

	std::vector<Mermi*>				m_mermiler;//dusman mermisi ile oyuncu fark� mermide tutuluyor. ikinci bi d��man mermi vekt�r�ne gerke yok
	std::vector<Spacemine*>			m_mines;
	std::vector<Spacebomb*>			m_bombs;
	std::vector<Spacestation*>		m_stations;
	std::vector<Efekt*>				m_efektler;
	std::vector<DusmanUcak*>		m_dusmanlar;//mermiler de burdan y�netilcek
	Spaceship	*					m_oyuncu;

	void nesneleriHareketEttir();
	void nesneleriCiz(sf::RenderWindow& pencere);

};

