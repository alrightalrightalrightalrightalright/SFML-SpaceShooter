#pragma once
#include "Animatable.hpp"
#include "Mermi.hpp"

//TODO: d??man u?ak ile ortak bir parent s?n?f yap

//oyuncunun y?netti?i oyuncuya ait uzay gemisi s?n?f?
class Spaceship:public  Animatable
{
public:
	Spaceship();

	void HaritadanCikti() override;
	void hareketEt();
	void atesEt();
	void hasarAl();
	int getKalanCan();

	int				m_cerceveIndex;//i?lenen ?er?eve indisi //get, set, incr gibi metotlara gerek var m??
private:
	int				m_atesEtmeCD;//frame cinsinden ate? etme cooldownu
	int				m_kalanCan;

};

 