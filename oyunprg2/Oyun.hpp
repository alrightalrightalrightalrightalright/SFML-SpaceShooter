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

//BUNLAR NEDEN EN A�A�IDA OLMAK ZORUNDA?
#include "OyunZekasi.hpp"
#include "Onbellek.hpp"
//VE NEDEN SADECE .CPP DOSYALARINDA �NCLUDE EDEB�L�YORUM? 


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
	OyunZekasi			m_oyunZekasi;
	DusmanUcak*	m_testDusmanUcak;
	DusmanUcak*	m_testDusmanUcak1;
	Spacebomb* bombruh ;
	Spacestation* stattt ;
	Spacemine* minee ;

	Mermi		m_mermi;
	Spaceship*	m_spaceship;
	sf::Vector2i	m_blok_margin;
	//vekt�r kullan�m�ndan dolay� blok nesnesi olu�turulduktan sonra vekt�re eklendi�inde
	//varsay�lan ctor ile eklendi�inden blok i�ersindeki texture alan� kayboluyor ve spiretler g�z�km�yor
	//bu y�zden pointer kullanarak new ile her bi nesneye �zel alan tahsil edilirse sorun olmuyor.

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
	int			m_frameCtr;//frame counter bir �eylerle oynamajk i�in
};