#pragma once

#include "Pencere.hpp"
#include "Spaceship.hpp"
#include "Mermi.hpp"
#include "DusmanUcak.hpp"
#include "Efekt.hpp"

//t�m oyun i�in nesneleri y�neten s�n�f. hareket, �arp��ma kontrolu vs gibi t�m kontrol mekanizmalar�n� y�r�t�r.

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
	//TODO: mermilerin gemide de�il de burada tutulmas� daha mant�kl�.

	std::vector<Efekt*>				m_efektler;
	std::vector<DusmanUcak*>		m_dusmanlar;//mermiler de burdan y�netilcek
	Spaceship	*				m_oyuncu;

	void hareketEttir();
	void ciz(sf::RenderWindow& pencere);

};

