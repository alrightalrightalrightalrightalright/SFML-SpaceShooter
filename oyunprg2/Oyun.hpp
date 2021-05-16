#pragma once

#include "Pencere.hpp"
#include "Buton.hpp"
#include "Pad.hpp"
#include "Top.hpp"
#include "Blok.hpp"
#include "Duvar.hpp"
#include "Spaceship.hpp"
#include "Mermi.hpp"
#include "DusmanUcak.hpp"
#include "Efekt.hpp"
#include "Onbellek.hpp"



#define PI   3.141592653589793238
//TODO: framecounter cizilebilir implement

class Oyun
{
public:
	Oyun();
	~Oyun();
	void btnYeniOyunTikla();
	void btnCikisTikla();
	void girisKontrol();
	void sahneGuncelle();
	void sahneCiz();
	void saatiYenidenBaslat();
	bool bittimi();
	void menuAyarla();
	void menuCiz();
	void calis();
	void carpis();
	void arkaPlanOlustur() ;
	void topCarpiyorMu();
private:
	sf::Texture			m_kaplama_arkaplan;
	sf::Sprite			m_sprite_arkaplan;

	DusmanUcak*	m_testDusmanUcak;
	DusmanUcak*	m_testDusmanUcak1;
	Pad			m_pad;
	Top			m_top;
	Blok		m_blok;
	Mermi		m_mermi;
	Duvar		m_ornekDuvar;
	Spaceship*	m_spaceship;
	sf::Vector2i	m_blok_margin;
	//vektör kullanýmýndan dolayý blok nesnesi oluþturulduktan sonra vektöre eklendiðinde
	//varsayýlan ctor ile eklendiðinden blok içersindeki texture alaný kayboluyor ve spiretler gözükmüyor
	//bu yüzden pointer kullanarak new ile her bi nesneye özel alan tahsil edilirse sorun olmuyor.
	std::vector<Blok*>		m_bloklar;
	std::vector<Duvar*>		m_duvarlar;

	std::vector<Efekt*>		m_efektler;
	Efekt* m_ornekEfekt;

	std::vector<Mermi*>		m_mermiler_oyuncu;
	std::vector<Mermi>		m_mermiler_dusmanlar;

	/////////////
	Pencere		m_pencere;
	Buton		m_btnYeniOyun;
	Buton		m_btnCikis;
	sf::Font	m_font;
	sf::Clock	m_saat;
	sf::Time	m_gecenSure;
	bool		m_kapalimi;
	bool		m_yeniOyunTiklandimi;
	float		m_cerceveSuresi;
	int			m_frameCtr;//frame counter bir þeylerle oynamajk için
};