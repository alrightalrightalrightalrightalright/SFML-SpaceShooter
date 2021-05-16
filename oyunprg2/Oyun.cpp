#include "Oyun.hpp"
#include<iostream>
#include "NesneYonetici.hpp"

Oyun::Oyun()
{


	//TEMEL DEĞİŞKENLER
	m_kapalimi = false;
	m_yeniOyunTiklandimi = false;	
	Onbellek asf= Onbellek::getInstance();
	m_cerceveSuresi = 1.0f / 60.0f;
	menuAyarla();
	auto boyut = m_pencere.pencereGetir().getSize();

	arkaPlanOlustur();
	m_pencere.pencereGetir();
	sf::Vector2u pencereBoyut = m_pencere.pencereGetir().getSize();


	m_spaceship = new Spaceship();
	m_testDusmanUcak1 = DusmanUcak::YarasaUcak();
	m_testDusmanUcak = DusmanUcak::KucukUcak();
	

	m_frameCtr = 0;

	m_ornekEfekt = new Efekt(sf::Vector2f( 212, 42));
	
	static NesneYonetici &oyunmotoru = NesneYonetici::getInstance();
	oyunmotoru.m_oyuncu= m_spaceship;
	oyunmotoru.m_dusmanlar.push_back(m_testDusmanUcak);
	oyunmotoru.m_dusmanlar.push_back(m_testDusmanUcak1);
}

Oyun::~Oyun()
{
}



void Oyun::btnYeniOyunTikla()
{
	m_yeniOyunTiklandimi = true;
	Onbellek asf = Onbellek::getInstance();

}

void Oyun::btnCikisTikla()
{
	m_kapalimi = true;
}

void Oyun::girisKontrol()
{
	m_pencere.olayKontrol();
	/*
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		m_siradakiYon = YON::SAG;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		m_siradakiYon = YON::SOL;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		m_siradakiYon = YON::YUKARI;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		m_siradakiYon = YON::ASAGI;*/
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		m_top.setHareketEdiyor(true);
		m_top.setYonetilebilir(false);


		//mermi ateşle
		m_spaceship->atesEt();
		m_testDusmanUcak->atesEt();
		m_testDusmanUcak1->atesEt();
	}
}

void Oyun::sahneGuncelle()
{

	if (m_gecenSure.asSeconds() >= m_cerceveSuresi)
	{
		m_gecenSure -= sf::seconds(m_cerceveSuresi);

		if (!m_yeniOyunTiklandimi)return;

		if (m_frameCtr >= 30) {
			Efekt* patlama = new Efekt(*Onbellek::getInstance().m_patlamaEfekt);
			//Efekt* patlama = new Efekt(*m_ornekEfekt);
			patlama->_rastgelelikVer();
			//Efekt fe =  Efekt(sf::Vector2f(3,3));
			m_efektler.push_back(patlama);
			m_frameCtr = 0;
			delete patlama;
		}
		

		topCarpiyorMu();

		NesneYonetici& yonetici= NesneYonetici::getInstance();
		yonetici.hareketEttir();

		//HAREKET ET VE FRAMECTR++ BURDAYDI

		m_frameCtr++;
	}
}

void Oyun::sahneCiz()
{
	m_pencere.cizimeBasla();
	if (m_yeniOyunTiklandimi)
	{
		m_pencere.ciz(m_sprite_arkaplan);
		
		NesneYonetici& yonetici = NesneYonetici::getInstance();
		yonetici.ciz(m_pencere.pencereGetir());


	}
	else
	{
		menuCiz();
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

//x2 = cosbetax1−sinbetay1
//y2 = sinbetax1 + cosbetay
//https://matthew-brett.github.io/teaching/rotation_2d.html
sf::Vector2f rotateBy(float beta, sf::Vector2f v)
{
	sf::Vector2f yeni = sf::Vector2f();

	yeni.x = cos(beta) * v.x - sin(beta) * v.y;
	yeni.y = sin(beta) * v.x + cos(beta) * v.y;

	return yeni;
}

void Oyun::carpis() {
}

void Oyun::topCarpiyorMu() {
	//harita dışına taşma kontrol:

	/*
	auto konum = m_top.getKonum();
	auto boyut = m_pencere.pencereGetir().getSize();

	float angle = atan2(konum.y, konum.x);


	//pencereye(kenarlara) çarpma kontrol:
	/*Özetle pencere kenarları + duvarların boyutu kadar yakınlığa çarpma kontorl ediliyor ve ona
	göre top sekiyor. yani her bir duvara tek tek çarptı mı kontrölü yapılmıyor performans gereği.
	if (konum.x + m_ornekDuvar.getBoyut().x <= m_top.m_sprite.getGlobalBounds().width) { carpis(); }//sol
	else if (konum.y + m_ornekDuvar.getBoyut().y <= m_top.m_sprite.getGlobalBounds().height) { carpis(); }//üst
	else if (konum.x + 2*m_ornekDuvar.getBoyut().x >= boyut.x) { 
		carpis(); }//sağ
	else if (konum.y +2*m_ornekDuvar.getBoyut().y >= boyut.y) { carpis(); }//alt

	//pade çarpma kontorl
	if (m_top.m_sprite.getGlobalBounds().intersects(m_pad.getSpriteBounds()))
		carpis();
	*/


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
