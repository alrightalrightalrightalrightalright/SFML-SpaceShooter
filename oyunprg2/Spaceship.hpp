#pragma once
#include "Animatable.hpp"
#include "Mermi.hpp"

/*
ÇARE LOOP PATTERNİNDEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE !!!!!!!! mi?
*/

//oyuncunun yönettiği oyuncuya ait uzay gemisi sınıfı
class Spaceship:public  Animatable
{
public:
	Spaceship();

	void HaritadanCikti() override;
	void hareketEt();
	void atesEt();

	std::vector<Mermi*>		m_mermiler;

	int				m_cerceveIndex;//işlenen çerçeve indisi //get, set, incr gibi metotlara gerek var mı?

private:
	int				m_atesEtmeCD;//frame cinsinden ateş etme cooldownu

};

 