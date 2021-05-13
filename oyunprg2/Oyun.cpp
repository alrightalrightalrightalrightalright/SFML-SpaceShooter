#include "Oyun.hpp"
#include<iostream>


Oyun::Oyun()
{
	//TEMEL DEĞİŞKENLER
	m_kapalimi = false;
	m_yeniOyunTiklandimi = false;

	m_cerceveSuresi = 1.0f / 60.0f;
	menuAyarla();
	auto boyut = m_pencere.pencereGetir().getSize();

	arkaPlanOlustur();
	m_pencere.pencereGetir();
	//BLOKLARI YERLEŞTİR MATRİS ŞEKLİNDE
	m_blok_margin.x = 5;
	m_blok_margin.y = 5;
	auto baslangicX = m_pencere.pencereGetir().getSize().x / 8;
	auto baslangicY = m_pencere.pencereGetir().getSize().y / 12;
	for (int i = 0; i < 10; i++) //satır
		for (int j = 0; j < 6; j++) {//sütun

			Blok* b = new  Blok(sf::Vector2f(
				baslangicX + i * m_blok_margin.x + (i * m_blok.m_sprite.getGlobalBounds().width),
				baslangicY + j * m_blok_margin.y + (j * m_blok.m_sprite.getGlobalBounds().height)));

			m_bloklar.push_back(b);
		}

	sf::Vector2u pencereBoyut = m_pencere.pencereGetir().getSize();



	//DUVARLARI DİZ
	Duvar* ddd = new Duvar();
	auto asdqweqw = ddd->m_sprite.getGlobalBounds();
	for (int i = 0; i < pencereBoyut.x / asdqweqw.width; i++)
	{

		int margin = 1;
		//üst duvar
		Duvar* d = new Duvar();
		d->setKonum(sf::Vector2f(i * margin + (i * d->m_sprite.getGlobalBounds().width), 0));
		m_duvarlar.push_back(d);

		//alt duvar
		Duvar* dd = new Duvar();
		dd->setKonum(sf::Vector2f(i * margin + (i * dd->m_sprite.getGlobalBounds().width),
			pencereBoyut.y - dd->m_sprite.getGlobalBounds().height));
		m_duvarlar.push_back(dd);
	}
	for (int i = 0; i < pencereBoyut.y / asdqweqw.height; i++)
	{
		int margin = 1;

		Duvar* d = new Duvar();
		d->setKonum(sf::Vector2f(0, i * margin + (i * d->m_sprite.getGlobalBounds().height)));
		m_duvarlar.push_back(d);

		Duvar* dd = new Duvar();
		dd->setKonum(sf::Vector2f(pencereBoyut.x - dd->m_sprite.getGlobalBounds().width,
			i * margin + (i * dd->m_sprite.getGlobalBounds().height)));
		m_duvarlar.push_back(dd);
	}

	//PADİ KOY
	m_pad.setKonum(sf::Vector2f(pencereBoyut.x / 2, pencereBoyut.y
		- m_pad.getSpriteBounds().height - m_duvarlar.at(0)->m_sprite.getGlobalBounds().height));
	
	//TOPU PADE KOY
	auto bepsiasidfas = m_pad.getSpriteBounds();
	m_top.setKonum(sf::Vector2f(pencereBoyut.x / 2, pencereBoyut.y - m_pad.getSpriteBounds().height
		- m_top.m_sprite.getGlobalBounds().height - m_duvarlar.at(0)->m_sprite.getGlobalBounds().height));// /2?
	m_top.setPadHiz(sf::Vector2f(m_pad.getHiz().x, 0));
	///////////////////////////////////////////////////////////////

	m_testDusmanUcak1 = DusmanUcak::YarasaUcak();
	

	m_frameCtr = 0;

	m_ornekEfekt = new Efekt(sf::Vector2f( 212, 42));

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
		m_spaceship.atesEt();
		m_testDusmanUcak.atesEt();
		m_testDusmanUcak1.atesEt();
	}
}

void Oyun::sahneGuncelle()
{

	if (m_gecenSure.asSeconds() >= m_cerceveSuresi)
	{
		m_gecenSure -= sf::seconds(m_cerceveSuresi);

		if (!m_yeniOyunTiklandimi)return;

		if (m_frameCtr >= 30) {
			Efekt* patlama = new Efekt(*m_ornekEfekt);
			patlama->_rastgelelikVer();
			//Efekt fe =  Efekt(sf::Vector2f(3,3));
			m_efektler.push_back(patlama);
			m_frameCtr = 0;
		}
		
		for (auto siradaki : m_spaceship.m_mermiler)
		{
			siradaki->hareketEt();
		}


		for (auto siradaki : m_testDusmanUcak.m_mermiler)
		{
			siradaki->hareketEt();
		}

		for (auto siradaki : m_testDusmanUcak1.m_mermiler)
		{
			siradaki->hareketEt();
		}

		topCarpiyorMu();
		m_pad.hareketEt();
		m_top.hareketEt();

		m_spaceship.hareketEt();
		m_testDusmanUcak.hareketEt();
		m_testDusmanUcak1.hareketEt();


		m_spaceship.m_cerceveIndex++;
		m_testDusmanUcak.m_cerceveIndex++;
		m_testDusmanUcak1.m_cerceveIndex++;
		m_frameCtr++;
	}
}

void Oyun::sahneCiz()
{
	m_pencere.cizimeBasla();
	if (m_yeniOyunTiklandimi)
	{
		m_pencere.ciz(m_sprite_arkaplan);

		
		m_mermi.ciz(m_pencere.pencereGetir());
		m_spaceship.ciz(m_pencere.pencereGetir());
		//m_pad.ciz(m_pencere.pencereGetir());
		//m_top.ciz(m_pencere.pencereGetir());
		m_testDusmanUcak.ciz(m_pencere.pencereGetir());
		m_testDusmanUcak1.ciz(m_pencere.pencereGetir());


		for (auto siradaki : m_spaceship.m_mermiler)
		{
			//keşke burayı sınıfın içersinden halledebilsem
			if (!siradaki->haritaDisindaMi())
				siradaki->ciz(m_pencere.pencereGetir());
			else {
				m_spaceship.m_mermiler.erase(std::remove(m_spaceship.m_mermiler.begin(),
					m_spaceship.m_mermiler.end(), siradaki), m_spaceship.m_mermiler.end());
				delete siradaki;
			}
		}


		for (auto siradaki : m_testDusmanUcak.m_mermiler)
		{
			//keşke burayı sınıfın içersinden halledebilsem
			if (!siradaki->haritaDisindaMi())
				siradaki->ciz(m_pencere.pencereGetir());
			else {
				m_testDusmanUcak.m_mermiler.erase(std::remove(m_testDusmanUcak.m_mermiler.begin(),
					m_testDusmanUcak.m_mermiler.end(), siradaki), m_testDusmanUcak.m_mermiler.end());
				delete siradaki;
			}
		}


		for (auto siradaki : m_testDusmanUcak1.m_mermiler)
		{
			//keşke burayı sınıfın içersinden halledebilsem
			if (!siradaki->haritaDisindaMi())
				siradaki->ciz(m_pencere.pencereGetir());
			else {
				m_testDusmanUcak1.m_mermiler.erase(std::remove(m_testDusmanUcak1.m_mermiler.begin(),
					m_testDusmanUcak1.m_mermiler.end(), siradaki), m_testDusmanUcak1.m_mermiler.end());
				delete siradaki;
			}
		}


		// BUĞHŞIPPGPFĞĞ ĞOHAĞĞĞĞĞĞĞHHPPPP PATLAMA OLDU BURDA
	
		for (auto siradaki : m_efektler)
		{
			if(!siradaki->m_efektBitti)
				siradaki->ciz(m_pencere.pencereGetir()); 
			else {
				m_efektler.erase(std::remove(m_efektler.begin(),
					m_efektler.end(), siradaki), m_efektler.end());
				delete siradaki;
			}

		}
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
	//çarptığı yere göre simetrisini almaya çalıştım. böylece hız vektörü geri sekmiş gibi 
	//bir değer alabilir. Biraz tuhaf çalışıyor ama biraz kaos iyidir.
	m_top.m_hizv = rotateBy(180, m_top.m_hizv);
	m_top.hareketEt();
	m_top.ciz(m_pencere.pencereGetir());


}

void Oyun::topCarpiyorMu() {
	//harita dışına taşma kontrol:


	auto konum = m_top.getKonum();
	auto boyut = m_pencere.pencereGetir().getSize();

	float angle = atan2(konum.y, konum.x);


	//pencereye(kenarlara) çarpma kontrol:
	/*Özetle pencere kenarları + duvarların boyutu kadar yakınlığa çarpma kontorl ediliyor ve ona
	göre top sekiyor. yani her bir duvara tek tek çarptı mı kontrölü yapılmıyor performans gereği.*/
	if (konum.x + m_ornekDuvar.getBoyut().x <= m_top.m_sprite.getGlobalBounds().width) { carpis(); }//sol
	else if (konum.y + m_ornekDuvar.getBoyut().y <= m_top.m_sprite.getGlobalBounds().height) { carpis(); }//üst
	else if (konum.x + 2*m_ornekDuvar.getBoyut().x >= boyut.x) { 
		carpis(); }//sağ
	else if (konum.y +2*m_ornekDuvar.getBoyut().y >= boyut.y) { carpis(); }//alt

	//pade çarpma kontorl
	if (m_top.m_sprite.getGlobalBounds().intersects(m_pad.getSpriteBounds()))
		carpis();
 
	for (auto siradaki : m_bloklar)
	{

		if (m_top.m_sprite.getGlobalBounds().intersects(siradaki->m_sprite.getGlobalBounds())) {
			if (!siradaki->m_silindi) {
				carpis();
				siradaki->kiril();
			}
		}


	}

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
