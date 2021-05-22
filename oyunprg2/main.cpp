#include <SFML/Graphics.hpp>
#include <iostream>
#include<functional>
#include "Oyun.hpp"
#include <stdlib.h>     
#include <time.h>    

#include <list>

int main()
{

	/*
	std::vector<int*> vekt = std::vector<int*>();
	int* ozel = new int;
	*ozel = 99;

	for (size_t i = 0; i < 5; i++)
	{
		int* yenisayi = new int;
		*yenisayi = i;
		if (i == 2)vekt.push_back(ozel);
		vekt.push_back(yenisayi);
	}

	// 0 1 99 2 3 4

	for (auto itr = vekt.begin(); itr != vekt.end();itr++) {
		if (*itr == vekt.back()) {

			if (**itr == 4) {
				std::cout << **itr << " silindi" << std::endl;
				vektordenNesneSil(*itr, vekt);
			}
			break;
		}
		std::cout << **itr << std::endl;

		if (**itr ==4) {
			std::cout << **itr<< " silindi" << std::endl;
			vektordenNesneSil(*itr, vekt);
		}
		
		//SON ELEMANDA MIYIMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
		bool vaw = *itr == vekt.back();
		std::cout << "tir: " << vaw << " " << std::endl;

	}

	
	return 3;
		for (auto itr : vekt) {
		if (*itr == 3) {
			vektordenNesneSil(itr, vekt); 
			itr = *vekt.begin();
			continue;
		}
		std::cout << *itr << std::endl;
	}
	
	*/
	/*	if (*itr == vekt.back()) {
				vektordenNesneSil(*itr, vekt);
				continue;
			}
	std::list<int*> vekt = std::list<int*>();
	int* ozel = new int;
	*ozel = 99;

	for (size_t i = 0; i < 5; i++)
	{
		int* yenisayi = new int;
		*yenisayi = i;
		if (i == 2)vekt.push_back(ozel);
		vekt.push_back(yenisayi);
	}
	//0 1 2 3 4
	//arremove(vekt, ozel);

	for (auto itr : vekt) {
		if (itr == ozel) { vekt.remove(ozel); }
		std::cout << *itr << std::endl;
	}
	
	// null 0 1 2 3 4
	return 3;
	*/
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
	oyun.godMode = true;
	oyun.calis();


	return 0;
}