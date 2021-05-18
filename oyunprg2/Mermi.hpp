#pragma once
#include "Cizilebilir.hpp"
#include "GemiTuru.hpp"

class Mermi: public Cizilebilir
{

public:
	void HaritadanCikti() override;
	Mermi(GEMI_TURU kaynak=GEMI_TURU::oyuncuUcak);
	void hareketEt();
	GEMI_TURU			m_kaynakGemi;//gemiyi mi tutsam?


};

