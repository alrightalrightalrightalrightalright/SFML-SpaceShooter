#pragma once
#include "Animatable.hpp"

class Spacemine :public  Animatable
{
private:
	int					m_rotatFactor;
public:
	Spacemine(sf::Vector2f konum);
	void HaritadanCikti() override;
	void hareketEt();
};

