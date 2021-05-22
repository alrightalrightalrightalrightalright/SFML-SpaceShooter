#include "Spacebomb.hpp"
#include "NesneYonetici.hpp"

Spacebomb::Spacebomb(sf::Vector2f konum)
	:Animatable(3, assets_loc + "uzay\\Spacebombs\\", sf::IntRect(54,61,156,115),1, 1)
{
	//scale edebilmek için ilk spriteyý yüklüyoruz
	olustur("uzay\\Spacebombs\\1", sf::IntRect(54, 61, 156, 115), sf::Vector2f(1, 1));

	float scaleY = 1 / (m_sprite.getGlobalBounds().width / 50);//hedef yükseklik
	float scaleX = 1 / (m_sprite.getGlobalBounds().height / 50);//hedef geniþlik
	m_sprite.scale(sf::Vector2f(scaleY, scaleX));

	m_hiz = sf::Vector2f(0, 0.5 + rand() % 50 / 100.0);//[.5,1.00]
	m_konum = konum;

}

void Spacebomb::HaritadanCikti()
{
	//vektordenNesneSil(this, NesneYonetici::getInstance().m_bombs);
}

void Spacebomb::hareketEt()
{
	m_konum += m_hiz;
}
