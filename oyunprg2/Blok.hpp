#pragma once

#include "Pencere.hpp"

class Blok
{
public:
	Blok();
	Blok(sf::Vector2f  konum);
	~Blok();
	void ciz(sf::RenderWindow& pencere);
	void olustur();
	void kiril();

	//private:
	sf::Vector2f		m_konum;
	sf::Texture			m_kaplama;
	sf::Sprite			m_sprite;
	sf::String			m_blokDosyaYol;
	sf::String			m_blokKirikDosyaYol;

	bool				m_silindi;
	int					m_kalan_vurus;

};

