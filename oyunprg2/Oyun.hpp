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
	//vektör kullanýmýndan dolayý blok nesnesi oluþturulduktan sonra vektöre eklendiðinde
	//varsayýlan ctor ile eklendiðinden blok içersindeki texture alaný kayboluyor ve spiretler gözükmüyor
	//bu yüzden pointer kullanarak new ile her bi nesneye özel alan tahsil edilirse sorun olmuyor.

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