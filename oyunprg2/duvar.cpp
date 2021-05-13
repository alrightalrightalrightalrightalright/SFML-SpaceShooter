#include "duvar.hpp"
#include <iostream>
#include "Ortak.hpp"

/*43 45
217 219
h=w= 174 
*/



static const char* duvarlar[] = { "brick",
"brick_blue",
"brick_pink_side",
"brick_red"
};

Duvar::Duvar() {
	m_konum = sf::Vector2f(320, 125);
	olustur();
}
void Duvar::setKonum(sf::Vector2f konum) {
	m_konum = konum;
}

//duvar bloklarý kare olmayabilir de, bu yüzden vektorde tutuluyor boyutlarý.
sf::Vector2f Duvar::getBoyut() {
	return m_boyut;
}


void Duvar::olustur() {
	sf::String secili = duvarlar[rand() % 4];
	m_duvarDosyaYol = assets_loc+"Walls\\" + secili + ".png";

	if (!m_kaplama.loadFromFile(m_duvarDosyaYol, sf::IntRect(43, 45, 174, 174)))
		int hatavarburdat = 4314;
	m_sprite.setTexture(m_kaplama); 
	m_sprite.setScale(0.10f, 0.10f);

	m_boyut = sf::Vector2f(m_sprite.getGlobalBounds().height, m_sprite.getGlobalBounds().width);
}

void Duvar::ciz(sf::RenderWindow& pencere)
{
	m_sprite.setPosition(m_konum); 
	pencere.draw(m_sprite);
}