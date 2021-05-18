#include "Mermi.hpp"
#include "NesneYonetici.hpp"



Mermi::Mermi(GEMI_TURU kaynak)
{
	m_konum = sf::Vector2f(220, 150);
	m_hiz = sf::Vector2f(0, 5);
	m_kaynakGemi= kaynak;

	sf::String dosya = m_kaynakGemi == GEMI_TURU::oyuncuUcak ? "bullet":"bullet_red" ;
	olustur("uzay\\" + dosya, sf::IntRect(44, 25, 39, 70));

	if (m_kaynakGemi != GEMI_TURU::oyuncuUcak) {
		m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2, m_sprite.getLocalBounds().height / 2);
		m_sprite.rotate(180);
		m_sprite.setOrigin(m_sprite.getLocalBounds().width, m_sprite.getLocalBounds().height);
	}
}


void Mermi::HaritadanCikti()
{
	std::cout << "mermi: " << this << "silindi." << std::endl;
	NesneYonetici& allah = NesneYonetici::getInstance();
  	vektordenNesneSil(this,allah.m_mermiler);
}

void Mermi::hareketEt() {
	sf::Vector2f artis;

	if (m_kaynakGemi != GEMI_TURU::oyuncuUcak)
		artis += m_hiz;

	else 
		artis += -m_hiz;

	m_konum += artis;

}