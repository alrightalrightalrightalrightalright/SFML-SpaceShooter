#include "Spacestation.hpp"
#include "NesneYonetici.hpp"

Spacestation::Spacestation(sf::Vector2f konum)
	:Animatable(3, assets_loc + "uzay\\comm\\", sf::IntRect(230, 227, 582, 569), 1, 1)
{
	//scale edebilmek için ilk spriteyý yüklüyoruz
	olustur("uzay\\comm\\1", sf::IntRect(230, 227, 582, 569), sf::Vector2f(1, 1));

	float scaleY = 1 / (m_sprite.getGlobalBounds().width / 50);//hedef yükseklik
	float scaleX = 1 / (m_sprite.getGlobalBounds().height / 50);//hedef geniþlik
	m_sprite.scale(sf::Vector2f(scaleY, scaleX));

	m_konum = konum;
	m_hiz = sf::Vector2f(0, 0.5 + rand()%75 /100.0);//[.5,1.25]
	m_rotatFactor = rand() % 2 == 0 ? 1 : -1;//dönüþ yönü(+,-) de çarpaný(1)

	//tam ortadan rotate için
	m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2, m_sprite.getLocalBounds().height / 2);

}
void Spacestation::HaritadanCikti()
{
	vektordenNesneSil(this, NesneYonetici::getInstance().m_stations);
}

void Spacestation::hareketEt()
{
	m_sprite.rotate(m_hiz.y * m_rotatFactor);
	m_konum += m_hiz;
}
