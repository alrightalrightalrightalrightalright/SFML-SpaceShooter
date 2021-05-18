#pragma once
#include "Spaceship.hpp"
#include "Mermi.hpp"
#include "DusmanUcak.hpp"
#include "Efekt.hpp"
#include "Spacebomb.hpp"
#include "Spacemine.hpp"
#include "Spacestation.hpp"

/*Oyun nesnelerinin örneklerinin tutulduðu sýnýf. Bu sýnýftan üretilen nesne ile
* oyun nesnelerinden birer örnek nesne üretilecek ve oyun esnasýnda diðer tüm oyun
* nesneleri bu nesneden kopyalanarak oluþturulacak. Böylelikle her sprite gerektiren
* oyun nesnesini oluþtururken gereken resim dosyalarý için IO iþlemlerine gerek duyulmadan
* hýzlý yeni nesneler oluþturulacak.
*
* Gelecek implentasyonlarda bu sýnýf sadece resim dosyalarýný önbelleklemesi planlanmaktadýr.
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

