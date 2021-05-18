#pragma once
#include "Pencere.hpp"
#include "Ortak.hpp"

/*Oyunun yapay zekas�, t�m oyun mekani�i y�netiminden sorumludur.
* nesnelerin mekanikleri, hareketi, spawn� ve �l�m�n� y�netir.
* 
�imdilik sadece spawn var. hareketler �imdilik basit ve tek y�n.
tek y�n oldu�undan nesneler kendi hareket ediyor.
*/
class OyunZekasi
{
private:
	int m_spawnCD;//frame cinsinden
	int m_maxDusmanSayisi;
	int m_cerceveSayac;
	void DusmanKoy(sf::Vector2f konum);

public:
	OyunZekasi();
	
	void Kontrol(sf::RenderWindow& window);
};

