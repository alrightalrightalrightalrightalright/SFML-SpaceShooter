#pragma once

#include "Pencere.hpp"
#include "Spaceship.hpp"
#include "Mermi.hpp"
#include "DusmanUcak.hpp"
#include "Efekt.hpp"

//tüm oyun için nesneleri yöneten sýnýf. hareket, çarpýþma kontrolu vs gibi tüm kontrol mekanizmalarýný yürütür.

class NesneYonetici
{
private:
	NesneYonetici() {
		//m_dusmanlar = std::vector<DusmanUcak*>();
	}

public:
	static NesneYonetici& getInstance() {
		static NesneYonetici instance;
		return instance;
	}
	//TODO: mermilerin gemide deðil de burada tutulmasý daha mantýklý.

	std::vector<Efekt*>				m_efektler;
	std::vector<DusmanUcak*>		m_dusmanlar;//mermiler de burdan yönetilcek
	Spaceship	*				m_oyuncu;

	void hareketEttir();
	void ciz(sf::RenderWindow& pencere);

};

