#include "Efekt.hpp"

Efekt::Efekt(sf::Vector2f konum)
	:Animatable(16,assets_loc+ "uzay\\Effects\\1_",sf::IntRect(),0,0.5)
{
	olustur( "uzay\\Effects\\1_0", sf::IntRect(), sf::Vector2f(1, 1));
	m_konum = konum;

	m_efektBitti = false;

	_rastgelelikVer();

}



//efekt boyut, açý gibi deðerlere rastgelelik vererek çeþitlilik saðlanýyor.
void Efekt ::_rastgelelikVer() {
	// scale, rotate vs...
	m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2, m_sprite.getLocalBounds().height / 2);

	float scaleY = (float)(25 + rand() % 80) / 100;//rastgele %40 ila 80 scale
	float scaleX = (float)(25 + rand() % 80) / 100;

	//tam ortadan rotate için
	m_sprite.setScale(sf::Vector2f(scaleY, scaleX));
	m_sprite.rotate(rand() % 360);

	//eski origini kullanmak zor olur çünkü rotate ile çevrilmiþ bir spriteý köþesinden kullanmak gereksiz
	//m_sprite.setOrigin(m_sprite.getLocalBounds().width, m_sprite.getLocalBounds().height);
}
 
void Efekt::ciz(sf::RenderWindow& window)
{
	Animatable::ciz(window);
	if (currSpriteIndex == maxSpriteIndex - 1)
		m_efektBitti = true;
}

