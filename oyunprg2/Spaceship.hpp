#pragma once
#include "Animatable.hpp"
#include "Mermi.hpp"

/*
�ARE LOOP PATTERN�NDEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE !!!!!!!! mi?
*/

//oyuncunun y�netti�i oyuncuya ait uzay gemisi s�n�f�
class Spaceship:public  Animatable
{
public:
	Spaceship();

	void HaritadanCikti() override;
	void hareketEt();
	void atesEt();

	std::vector<Mermi*>		m_mermiler;

	int				m_cerceveIndex;//i�lenen �er�eve indisi //get, set, incr gibi metotlara gerek var m�?

private:
	int				m_atesEtmeCD;//frame cinsinden ate� etme cooldownu

};

 