#pragma once
#include "Animatable.hpp"

class Spacestation :public  Animatable
{
	float		m_rotatFactor;
public:
	Spacestation(sf::Vector2f konum);
	void HaritadanCikti() override;
	void hareketEt();
};

