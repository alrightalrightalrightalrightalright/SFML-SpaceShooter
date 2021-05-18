#pragma once
#include "Spaceship.hpp"
#include "Mermi.hpp"
#include "DusmanUcak.hpp"
#include "Efekt.hpp"
#include "Spacebomb.hpp"
#include "Spacemine.hpp"
#include "Spacestation.hpp"

/*Oyun nesnelerinin �rneklerinin tutuldu�u s�n�f. Bu s�n�ftan �retilen nesne ile
* oyun nesnelerinden birer �rnek nesne �retilecek ve oyun esnas�nda di�er t�m oyun
* nesneleri bu nesneden kopyalanarak olu�turulacak. B�ylelikle her sprite gerektiren
* oyun nesnesini olu�tururken gereken resim dosyalar� i�in IO i�lemlerine gerek duyulmadan
* h�zl� yeni nesneler olu�turulacak.
*
* Gelecek implentasyonlarda bu s�n�f sadece resim dosyalar�n� �nbelleklemesi planlanmaktad�r.
*
*/

 

class Onbellek
{
private:
	Onbellek();
	
public:       

	static Onbellek& getInstance() {
		static Onbellek instance;
		return instance;
	}

	Spaceship*				m_spaceship;
	Mermi		*			m_oyuncuMermi;
	Mermi		*			m_dusmanMermi;
	DusmanUcak	*			m_dusmanKucukUcak;
	DusmanUcak	*			m_dusmanYarasaUcak;
	Spacebomb* m_spaceBomb;
	Spacemine* m_spaceMine;
	Spacestation* m_spaceStation;
	Efekt				*	m_patlamaEfekt;
};

