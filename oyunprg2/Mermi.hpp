#pragma once
#include "Cizilebilir.hpp"
class Mermi: public Cizilebilir
{
private:
	bool				dusmaninMi;
	void HaritadanCikti() override;


public:
	Mermi(bool dusmaninMi=false);
	void hareketEt();


};

