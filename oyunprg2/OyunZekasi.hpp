#pragma once
#include "Pencere.hpp"
#include "Ortak.hpp"

/*Oyunun yapay zekasý, tüm oyun mekaniði yönetiminden sorumludur.
* nesnelerin mekanikleri, hareketi, spawný ve ölümünü yönetir.
* 
þimdilik sadece spawn var. hareketler þimdilik basit ve tek yön.
tek yön olduðundan nesneler kendi hareket ediyor.
*/
class OyunZekasi
{
private:
	int m_spawnCD;//frame cinsinden, her bir varlýðýn spawn cdsi
	int m_maxIstasyonSayisi;
	int m_maxDusmanSayisi;
	int m_maxMayinSayisi;
	int m_maxBombaSayisi;
	//burdaki bir deðer otomatik null oluyor? nasýl neden????

	int m_cerceveSayac;
	void DusmanKoy(sf::Vector2f konum);

public:
	OyunZekasi();
	
	void Kontrol(sf::RenderWindow& window);
};

