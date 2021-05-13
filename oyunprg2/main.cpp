#include <SFML/Graphics.hpp>
#include <iostream>
#include<functional>
#include "Oyun.hpp"
#include <stdlib.h>     
#include <time.h>       

int main()
{
	srand(time(NULL));

	Oyun oyun;
	oyun.calis();


	return 0;
}