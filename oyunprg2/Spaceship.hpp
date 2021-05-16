#pragma once
#include "Animatable.hpp"
#include "Mermi.hpp"

/*
ÇARE LOOP PATTERNÝNDEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE !!!!!!!! mi?
*/

//oyuncunun yönettiði oyuncuya ait uzay gemisi sýnýfý
class Spaceship:public  Animatable
{
public:
	Spaceship();

	void HaritadanCikti() override;
	void hareketEt();
	void atesEt();

	std::vector<Mermi*>		m_mermiler;

	int				m_cerceveIndex;//iþlenen çerçeve indisi //get, set, incr gibi metotlara gerek var mý?

private:
	int				m_atesEtmeCD;//frame cinsinden ateþ etme cooldownu

};

 