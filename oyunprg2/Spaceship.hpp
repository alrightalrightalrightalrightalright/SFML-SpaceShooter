#pragma once
#include "Animatable.hpp"
#include "Mermi.hpp"

//TODO: düþman uçak ile ortak bir parent sýnýf yap

//oyuncunun yönettiði oyuncuya ait uzay gemisi sýnýfý
class Spaceship:public  Animatable
{
public:
	Spaceship();

	void HaritadanCikti() override;
	void hareketEt();
	void atesEt();
	void hasarAl();
	int getKalanCan();

	int				m_cerceveIndex;//iþlenen çerçeve indisi //get, set, incr gibi metotlara gerek var mý?
private:
	int				m_atesEtmeCD;//frame cinsinden ateþ etme cooldownu
	int				m_kalanCan;

};

 