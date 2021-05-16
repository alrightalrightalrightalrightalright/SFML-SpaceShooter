#include <iostream>
#include "Onbellek.hpp"

Onbellek::Onbellek()
{
	std::cout << "önbellekleniyo viyuuu" << std::endl;
	m_spaceship = new Spaceship();
	m_oyuncuMermi= new Mermi();
	m_dusmanMermi= new Mermi(true);

	m_dusmanKucukUcak = DusmanUcak::KucukUcak();
	m_dusmanYarasaUcak =  DusmanUcak::YarasaUcak();
	m_patlamaEfekt	= new Efekt(sf::Vector2f(212, 42));

}
