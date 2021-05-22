#pragma once

#include "Pencere.hpp"
#include "Buton.hpp"
#include "Spaceship.hpp"
#include "Mermi.hpp"
#include "DusmanUcak.hpp"
#include "Efekt.hpp"
#include "Spacebomb.hpp"
#include "Spacemine.hpp"
#include "Spacestation.hpp"

//BUNLAR NEDEN EN AÞAÐIDA OLMAK ZORUNDA?
#include "OyunZekasi.hpp"
#include "Onbellek.hpp"
//VE NEDEN SADECE .CPP DOSYALARINDA ÝNCLUDE EDEBÝLÝYORUM? 


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
	void arkaPlanOlustur() ;

	bool godMode;
private:
	sf::Texture			m_kaplama_arkaplan;
	sf::Sprite			m_sprite_arkaplan;
	OyunZekasi			m_oyunZekasi;

	Spaceship*	m_spaceship;


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
	int			m_frameCtr;
};