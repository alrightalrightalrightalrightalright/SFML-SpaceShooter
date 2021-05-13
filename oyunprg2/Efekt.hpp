#pragma once
#include "Animatable.hpp"
//TODO: copy ctor veya operator overload ile rastgelelikver() yap.
class Efekt:public Animatable
{
private:
	float		m_animHizi;
public:
	Efekt(sf::Vector2f konum);
	void ciz(sf::RenderWindow& window);
	void _rastgelelikVer();

	bool		m_efektBitti;
};

