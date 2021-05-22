#include "Oyun.hpp"
#include<iostream>
#include "NesneYonetici.hpp"

Oyun::Oyun()
{

	godMode = false;
	m_kapalimi = false;
	m_yeniOyunTiklandimi = false;	
	m_cerceveSuresi = 1.0f / 60.0f;

	menuAyarla();

	arkaPlanOlustur();

	m_pencere.pencereGetir();
	sf::Vector2u pencereBoyut = m_pencere.pencereGetir().getSize();

	m_frameCtr = 0;

	m_spaceship = new Spaceship();
	m_spaceship->setKonum(sf::Vector2f(pencereBoyut.x/2-25,9* pencereBoyut.y/10  ));
	static NesneYonetici &oyunmotoru = NesneYonetici::getInstance();
	oyunmotoru.m_oyuncu= m_spaceship;

	//nesneleri başlatmak için. başka bir işlevi yok.
	Onbellek onbellek= Onbellek::getInstance();
}

Oyun::~Oyun()
{
}



void Oyun::btnYeniOyunTikla()
{
	m_yeniOyunTiklandimi = true;

}

void Oyun::btnCikisTikla()
{
	m_kapalimi = true;
}

void Oyun::girisKontrol()
{
	m_pencere.olayKontrol();

}

void Oyun::sahneGuncelle()
{

	if (m_gecenSure.asSeconds() >= m_cerceveSuresi)
	{
		m_gecenSure -= sf::seconds(m_cerceveSuresi);

		if (!m_yeniOyunTiklandimi)return;

		if (m_frameCtr >= 30) {
			//sürekli olay
		}
			
		NesneYonetici& yonetici= NesneYonetici::getInstance();

		yonetici.nesneleriHareketEttir();
		m_oyunZekasi.Kontrol(m_pencere.pencereGetir());

		m_frameCtr++;
	}
}

void Oyun::sahneCiz()
{
	m_pencere.cizimeBasla();

	if (!m_yeniOyunTiklandimi)
	{
		menuCiz();
		m_pencere.cizimiBitir();
		return;
	}
 
	m_pencere.ciz(m_sprite_arkaplan);
	NesneYonetici& yonetici = NesneYonetici::getInstance();
	yonetici.nesneleriCiz(m_pencere.pencereGetir());

	if (m_spaceship->getKalanCan() <= 0) {
		if (!godMode)
			exit(3);
	}

	m_pencere.cizimiBitir();
}

void Oyun::saatiYenidenBaslat()
{
	m_gecenSure += m_saat.restart();
}

bool Oyun::bittimi()
{
	if (m_kapalimi)
		return true;
	return m_pencere.kapandimi();
}

void Oyun::arkaPlanOlustur() {
	sf::String dosyayolu = assets_loc + "Background\\background.png";
	sf::Image img;
	img.loadFromFile(dosyayolu);

	m_kaplama_arkaplan.loadFromImage(img);
	m_sprite_arkaplan.setTexture(m_kaplama_arkaplan);
	m_sprite_arkaplan.setPosition(sf::Vector2f(0, 0));
}


void Oyun::menuAyarla()
{
	auto fonk = std::bind(&Oyun::btnYeniOyunTikla, this);
	m_btnYeniOyun.tiklaFonksiyonuEkle(fonk);
	fonk = std::bind(&Oyun::btnCikisTikla, this);
	m_btnCikis.tiklaFonksiyonuEkle(fonk);

	//DEBUG ONLY:
	if (m_font.loadFromFile(assets_loc + "fonts\\alev.ttf") != false)
	{
		m_btnCikis.font(m_font);
		m_btnYeniOyun.font(m_font);
	}
	m_btnYeniOyun.renk(sf::Color::Red);
	m_btnCikis.renk(sf::Color::Red);

	m_btnYeniOyun.yazi("Yeni Oyun");
	m_btnCikis.yazi(L"Çıkış");

	auto sahneBoyut = m_pencere.pencereGetir().getSize();
	auto btnBoyut = m_btnYeniOyun.boyutGetir();

	float x = (sahneBoyut.x - btnBoyut.x) / 2.0f;
	float y = (sahneBoyut.y - btnBoyut.y) / 2.0f;
	m_btnYeniOyun.konum(x, y);
	m_btnCikis.boyut(btnBoyut.x, btnBoyut.y);

	m_btnCikis.konum(x, y + 50);

	m_pencere.aracEkle(&m_btnYeniOyun);
	m_pencere.aracEkle(&m_btnCikis);
}


void Oyun::menuCiz()
{
	m_btnCikis.ciz(m_pencere.pencereGetir());
	m_btnYeniOyun.ciz(m_pencere.pencereGetir());
}

void Oyun::calis() {
	while (!bittimi())
	{
		girisKontrol();
		sahneGuncelle();
		sahneCiz();
		
		saatiYenidenBaslat();
	}
}
