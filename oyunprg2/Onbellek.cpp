#include <iostream>
#include "Onbellek.hpp"

Onbellek::Onbellek()
{
	m_spaceship = new Spaceship();
	m_oyuncuMermi= new Mermi();
	m_dusmanMermi= new Mermi(GEMI_TURU::yarasaUcak);

	m_dusmanKucukUcak = DusmanUcak::KucukUcak();
	m_dusmanYarasaUcak =  DusmanUcak::YarasaUcak();
	m_patlamaEfekt	= new Efekt(sf::Vector2f(212, 42));
	m_spaceBomb= new Spacebomb(sf::Vector2f(252, 42));
	m_spaceStation= new Spacestation(sf::Vector2f(252, 42));
	m_spaceMine= new Spacemine(sf::Vector2f(252, 42));
}
