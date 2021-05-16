#pragma once
#include "Pencere.hpp"
#include "Ortak.hpp"

//oyun esnas�nda dinamik i�leve sahip her t�rl� oyun nesnesi i�in bir s�n�f.
//hareket etme, animasyon, spriteye sahip olma gibi �zellikler bu s�n�f alt�nda ger�ekle�ir
class Cizilebilir
{
public:
	Cizilebilir();
	//~Cizilebilir();

	void ciz(sf::RenderWindow& window);
	
	void hareketEt();
	
	void olustur();
	void olustur(sf::String dosya, sf::IntRect area, sf::Vector2f scale = sf::Vector2f(0.3f, 0.3f));//0.165

	void setKonum(sf::Vector2f konum);
	sf::Vector2f getCenter();
	sf::Vector2f getKonum();
	
	void setHiz(sf::Vector2f hiz);
	void tasmaKontrol();
	sf::Vector2f getHiz();
	bool haritaDisindaMi();

	virtual void HaritadanCikti();
	sf::Vector2f _hareketEt();
	sf::FloatRect getSpriteBounds();

protected:
	sf::Vector2f		m_konum;
	sf::Texture			m_kaplama;
	sf::Sprite			m_sprite;
	sf::Vector2f		m_hiz;
	bool				m_haritaDisindaMi;

	sf::Vector2u		m_pencereBoyutlari;
};

