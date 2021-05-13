#include "Mermi.hpp"

void Mermi::HaritadanCikti()
{
	//delete this;
}

Mermi::Mermi(bool dusmaninMi)
{
	this->dusmaninMi = dusmaninMi;

	m_konum = sf::Vector2f(220, 150);
	m_hiz = sf::Vector2f(0, 5);

	sf::String dosya = !dusmaninMi? "bullet":"bullet_red" ;
	olustur("uzay\\" + dosya, sf::IntRect(44, 25, 39, 70));

	if (dusmaninMi) {
		m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2, m_sprite.getLocalBounds().height / 2);
		m_sprite.rotate(180);
		m_sprite.setOrigin(m_sprite.getLocalBounds().width, m_sprite.getLocalBounds().height);
	}
}


void Mermi::hareketEt() {
	sf::Vector2f artis;

	if (dusmaninMi)
		artis += m_hiz;

	else if (!dusmaninMi)
		artis += -m_hiz;

	m_konum += artis;

}