#pragma once
#include "Cizilebilir.hpp"
class Animatable: public Cizilebilir
{
protected:
	//neden cizilebilir'de tanýmlanmadý?: çünkü animasyonu olmayan
	//her çizilebilir nesnenin textur alaný sabittir. animasyon olmadýkça deðiþime gerek yok.
	//tekli sprite dosyalarý için nerde olduðu farketmese de birçok sprite içeren tek
	//resim dosyasý için bu tasarýmýn daha doðru olduðunu düþündük.
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

