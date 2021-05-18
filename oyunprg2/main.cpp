#include <SFML/Graphics.hpp>
#include <iostream>
#include<functional>
#include "Oyun.hpp"
#include <stdlib.h>     
#include <time.h>    



int main()
{/*
	std::vector<int*> vekt = std::vector<int*>();
	int* ozel = new int;
	*ozel = 99;

	for (size_t i = 0; i < 5; i++)
	{
		int* yenisayi = new int;
		*yenisayi = i;
		if (i == 0)vekt.push_back(ozel);
		vekt.push_back(yenisayi);
	}
	//0 1 2 3 4
	//arremove(vekt, ozel);


	for (auto it = vekt.rbegin(); it != vekt.rend(); ++it)
	{
		std::cout << **it << std::endl;
		if (*it == ozel) {
			arremove( vekt, ozel);
		}
	}
	// null 0 1 2 3 4
	return 3;*/
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