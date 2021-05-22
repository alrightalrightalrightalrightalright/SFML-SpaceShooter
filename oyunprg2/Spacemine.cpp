#include "Spacemine.hpp"
#include "NesneYonetici.hpp"

Spacemine::Spacemine(sf::Vector2f konum)
	:Animatable(2, assets_loc + "uzay\\Spacemines\\", sf::IntRect(8,9,230,230), 1, 1)
{
	//TODO: ctora hedef scale ekle
	//scale edebilmek için ilk spriteyý yüklüyoruz
	olustur("uzay\\Spacemines\\1", sf::IntRect(8, 9, 230, 230), sf::Vector2f(1, 1));

	float scaleY = 1 / (m_sprite.getGlobalBounds().width / 50);//hedef yükseklik
	float scaleX = 1 / (m_sprite.getGlobalBounds().height / 50);//hedef geniþlik
	m_sprite.scale(sf::Vector2f(scaleY, scaleX));

	m_hiz = sf::Vector2f(0, 0.5 + rand() % 75 / 100.0);//[.5,1.25]
	m_rotatFactor = rand() % 2 == 0 ?2 : -2;//dönüþ yönü(+,-) de çarpaný(2)
	//tam ortadan rotate için
	m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2, m_sprite.getLocalBounds().height / 2);
	
	m_konum = konum;

}


void Spacemine::HaritadanCikti()
{
	//vektordenNesneSil(this, NesneYonetici::getInstance().m_mines);
}

void Spacemine::hareketEt()
{
	m_sprite.rotate(m_hiz.y * m_rotatFactor);
	m_konum += m_hiz;
}
