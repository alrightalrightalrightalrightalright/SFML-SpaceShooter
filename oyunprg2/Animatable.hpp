#pragma once
#include "Cizilebilir.hpp"
class Animatable: public Cizilebilir
{
protected:
	//neden cizilebilir'de tan�mlanmad�?: ��nk� animasyonu olmayan
	//her �izilebilir nesnenin textur alan� sabittir. animasyon olmad�k�a de�i�ime gerek yok.
	//tekli sprite dosyalar� i�in nerde oldu�u farketmese de bir�ok sprite i�eren tek
	//resim dosyas� i�in bu tasar�m�n daha do�ru oldu�unu d���nd�k.
	sf::IntRect				m_textureArea;
	int						currSpriteIndex;

	int						maxSpriteIndex;
	float					m_animHiz;
	int						m_cerceveCtr;
	
	
	sf::String				animPath;
	std::vector<sf::Image>	resimler;
	void Animate();
	void Onbellekle();
public:
	Animatable(int maxSpriteIndex, sf::String animPath, sf::IntRect area= sf::IntRect(), int firstSpriteIndex=1, float animHiz=1.0f);
	void ciz(sf::RenderWindow& window);

};

