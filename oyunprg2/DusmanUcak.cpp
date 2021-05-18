#include "DusmanUcak.hpp"
#include "Onbellek.hpp"
#include "NesneYonetici.hpp"

DusmanUcak::DusmanUcak(sf::Vector2f konum,float ucakHizi,float mermiHizi, GEMI_TURU tur,
	int animSayisi, sf::String animLoc, sf::IntRect animArea,int atesMaxCD,int can)
	:Animatable(animSayisi, assets_loc + animLoc , animArea ) {

	m_ucakHizi = ucakHizi;
	m_mermiHizi = mermiHizi;
	m_konum = konum;
	m_hiz = sf::Vector2f(0, m_ucakHizi);
	m_gemiTuru = tur;
	m_kalanCan = can;

	sf::String secili = "1";
	//scale edebilmek için ilk spriteyý yüklüyoruz
	olustur(animLoc + secili, animArea);

	float scaleY = 1 / (m_sprite.getGlobalBounds().width / 50);//hedef yükseklik
	float scaleX = 1 / (m_sprite.getGlobalBounds().height / 50);//hedef yükseklik

	//tam ortadan rotate için
	m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2, m_sprite.getLocalBounds().height / 2);
	m_sprite.scale(sf::Vector2f(scaleY, scaleX));
	m_sprite.rotate(180);
	m_sprite.setOrigin(m_sprite.getLocalBounds().width, m_sprite.getLocalBounds().height);

	m_atesMaxCD = atesMaxCD;
	m_atesEtmeCD = 0;
	m_cerceveIndex = 0;
}


void DusmanUcak::atesEt() {
	//ateþ etme cooldownu(frame cinsinden) bittiyse tekrar ateþ et.
	if (m_cerceveIndex >= m_atesEtmeCD) {
		Mermi* yeniMermi = new Mermi(*Onbellek::getInstance().m_dusmanMermi);

		yeniMermi->setHiz(sf::Vector2f(0, m_mermiHizi));
		auto aeaf = getSpriteBounds();
		float xHizalama = (getSpriteBounds().width
			- yeniMermi->getSpriteBounds().width) / 2 ;
		yeniMermi->setKonum(getKonum() + sf::Vector2f(xHizalama, getSpriteBounds().height- 8));

		static NesneYonetici& oyunmotoru = NesneYonetici::getInstance();
		oyunmotoru.m_mermiler.push_back(yeniMermi);


		m_cerceveIndex = 0;
		m_atesEtmeCD = 30+rand() % m_atesMaxCD	;//30 frame ile 360 frame arasý ynai yarým sn ile 6sn arasý
	}
}


void DusmanUcak::HaritadanCikti()
{
	if (m_konum.y >= 100) {//100 rastgele, spawnlanýrken yok olmamasý için var.
		vektordenNesneSil(this, NesneYonetici::getInstance().m_dusmanlar);
	}
}

void DusmanUcak::hareketEt()
{
	if (m_konum.y > 0)
		atesEt();
	m_konum += m_hiz;
}
