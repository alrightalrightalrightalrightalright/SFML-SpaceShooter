#pragma once

#include "Pencere.hpp"

class Duvar
{
public:
	Duvar();
	void ciz(sf::RenderWindow& pencere);
	void olustur();

	//private:
	sf::Vector2f		m_konum;
	sf::Texture			m_kaplama;
	sf::Sprite			m_sprite;
	sf::String			m_duvarDosyaYol;
	void setKonum(sf::Vector2f konum);
	sf::Vector2f	 getBoyut();

	sf::Vector2f		m_boyut;
};

