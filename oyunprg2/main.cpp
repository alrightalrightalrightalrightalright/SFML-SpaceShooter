#include <SFML/Graphics.hpp>
#include <iostream>
#include<functional>
#include "Oyun.hpp"
#include <stdlib.h>     
#include <time.h>       

int main()
{
	/*
	Pencere p; 
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	EventControl ev(p.pencereGetir());


	while (!p.kapandimi())
	{
		ev.bepseafei();


		p.cizimeBasla();		
		p.ciz(shape);
		p.cizimiBitir();

	}
	*/












	srand(time(NULL));

	Oyun oyun;
	oyun.calis();


	return 0;
}