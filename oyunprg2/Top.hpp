#pragma once

#include "Pencere.hpp"
class Top
{
public:
	Top();
	//~Top();
	void ciz(sf::RenderWindow& pencere);
	void hareketEt();
	void olustur();

	sf::Vector2f	 getKonum();
	void setHareketEdiyor(bool deger);
	void setKonum(sf::Vector2f konum);
	void setYonetilebilir(bool deger);
	void setPadHiz(sf::Vector2f hiz);


	//private:
	sf::Vector2f		m_konum;
	sf::Texture			m_kaplama;
	sf::Sprite			m_sprite;

	sf::Vector2f		m_hizv;
	bool				m_hareketEdiyor;
	bool				m_yonetilebilir;
	sf::Vector2f		m_pad_hiz;

	sf::Vector2i					m_yon;
	float				m_hareketMiktari;

};

