#pragma once
#include "Animatable.hpp"

class Spacebomb :public  Animatable
{
private:
	void HaritadanCikti() override;
public:
	Spacebomb(sf::Vector2f konum);	
	void hareketEt();
};

