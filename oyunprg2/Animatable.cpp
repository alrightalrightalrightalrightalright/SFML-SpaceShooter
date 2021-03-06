#include "Animatable.hpp"
#include  <iostream>
Animatable::Animatable(int maxSpriteIndex, sf::String animPath, sf::IntRect area, int firstSpriteIndex,float animHiz)
{
	this->currSpriteIndex = firstSpriteIndex;
	this->maxSpriteIndex = maxSpriteIndex;
	this->animPath = animPath;
	this->m_textureArea = area;
	this->m_animHiz = animHiz;

	this->m_cerceveCtr = 0;

	Onbellekle();
}

//anim resimlerini tekrar tekrar kullanmak ?zere belle?e y?kle
void Animatable::Onbellekle()
{
	for (int i = currSpriteIndex; i <= maxSpriteIndex; i++)
	{
		sf::Image img;// = new sf::Image();
		bool bepsi = img.loadFromFile(animPath + std::to_string(i) + ".png");
		resimler.push_back(img);
	}

}



void Animatable::Animate()
{
	//TODO: yava?lat?lm??ta t?m animasyonlar? gez
	if (currSpriteIndex == maxSpriteIndex)
		currSpriteIndex = 1;
	else {
		//animasyon h?z?na g?re animate
		
		//h?zland?r
		if (m_animHiz >= 1) {
			currSpriteIndex += m_animHiz/1.0f;
			currSpriteIndex = currSpriteIndex > maxSpriteIndex ? maxSpriteIndex-1 : currSpriteIndex;
			m_cerceveCtr = 0;
		}
		//yava?lat
		else {
			if (1 / m_animHiz <= m_cerceveCtr) {
				currSpriteIndex++;
				m_cerceveCtr = 0;
			}
		}
		

	}
	int index = currSpriteIndex == 0 ? 0 : currSpriteIndex - 1;//1,2,3,4 olarak 4 anim varsa 0,1,2,3 oalrak eri?cek
	m_kaplama.loadFromImage(resimler.at(index), m_textureArea);//rokete g?re max height
	//m_kaplama.update(resimler.at(currSpriteIndex));
	//m_kaplama.update(resimler[currSpriteIndex]->getPixelsPtr());//??????????????????????????
	m_sprite.setTexture(m_kaplama);
}


void Animatable::ciz(sf::RenderWindow& window)
{
	Animate();
	Cizilebilir::ciz(window);
	m_cerceveCtr++;
}