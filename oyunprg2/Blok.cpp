#include "Blok.hpp"
#include <iostream>
#include "Ortak.hpp"

/*141 178

372 279

w=231 
h=101
*/
 const char* bloklar[] = { "brick_blue_small",
"brick_green_small",
"brick_pink_small",
"brick_violet_small",
"brick_yellow_small" };

static const char* kirikBloklar[] = { "brick_blue_small_cracked",
"brick_green_small_cracked",
"brick_pink_small_cracked",
"brick_violet_small_cracked",
"brick_yellow_small_cracked"
};

Blok::Blok() {
	m_konum = sf::Vector2f(320, 125);
	m_kalan_vurus = 2;
	olustur();
	m_silindi = false;
}
Blok::Blok(sf::Vector2f konum) {
	m_konum = konum;
	m_kalan_vurus = 2;
	olustur();
	m_silindi = false;
}
Blok::~Blok() {
	std::cout << "elveda..";
}

void Blok::olustur() {

	sf::String secili = bloklar[rand() % 5];
	m_blokDosyaYol = assets_loc+"Bricks\\" + secili +".png";
	m_blokKirikDosyaYol = assets_loc+ "\Bricks\\" + secili +"_cracked" + ".png";
	
	std::string s1 = m_blokDosyaYol;

	if(!m_kaplama.loadFromFile(m_blokDosyaYol, sf::IntRect(141, 178, 231, 101)))
		int hatavarburdat;
	m_sprite.setTexture(m_kaplama); 
	m_sprite.setScale(0.25f, 0.25f);
}

void Blok::kiril() {
	m_kalan_vurus--;

	switch (m_kalan_vurus)
	{
	case 1:
		m_kaplama.loadFromFile(m_blokKirikDosyaYol, sf::IntRect(141, 178, 231, 101));
		m_sprite.setTexture(m_kaplama);
		m_sprite.setScale(0.25f, 0.25f);
		break;
	case 0:
		m_silindi = true;
	default://bug
		//m_silindi = true;
		break;
	}



}

void Blok::ciz(sf::RenderWindow& pencere)
{
	if (m_silindi)return;
	m_sprite.setPosition(m_konum); // absolute position
	pencere.draw(m_sprite);

}