#include "DusmanUcak.hpp"
#include "Onbellek.hpp"

DusmanUcak::DusmanUcak(sf::Vector2f konum,float ucakHizi,float mermiHizi, GEMI_TURU tur,
	int animSayisi, sf::String animLoc, sf::IntRect animArea,int atesMaxCD)
	:Animatable(animSayisi, assets_loc + animLoc , animArea ) {

	m_ucakHizi = ucakHizi;
	m_mermiHizi = mermiHizi;
	m_konum = konum;
	m_hiz = sf::Vector2f(0, m_ucakHizi);
	m_gemiTuru = tur;

	sf::String secili = "1";
	olustur(animLoc + secili, animArea);

	float scaleY = 1 / (m_sprite.getGlobalBounds().width / 50);//hedef yükseklik
	float scaleX = 1 / (m_sprite.getGlobalBounds().height / 50);//hedef yükseklik

	//tam ortadan rotate için
	m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2, m_sprite.getLocalBounds().height / 2);
	m_sprite.scale(sf::Vector2f(scaleX, scaleY));
	m_sprite.rotate(180);
	m_sprite.setOrigin(m_sprite.getLocalBounds().width, m_sprite.getLocalBounds().height);

	m_atesMaxCD = atesMaxCD;
	m_atesEtmeCD = 0;
	m_cerceveIndex = 0;
}


void DusmanUcak::atesEt() {
	if (m_cerceveIndex >= m_atesEtmeCD) {
		Mermi* yeniMermi = new Mermi(*Onbellek::getInstance().m_dusmanMermi);

		yeniMermi->setHiz(sf::Vector2f(0, m_mermiHizi));
		auto aeaf = getSpriteBounds();
		float xHizalama = (getSpriteBounds().width
			- yeniMermi->getSpriteBounds().width) / 2 ;
		yeniMermi->setKonum(getKonum() + sf::Vector2f(xHizalama, getSpriteBounds().height- 8));
		m_mermiler.push_back(yeniMermi);

		m_cerceveIndex = 0;
		m_atesEtmeCD = 30+rand() % m_atesMaxCD	;//30 frame ile 360 frame arasý ynai yarým sn ile 6sn arasý
	}
}


void DusmanUcak::HaritadanCikti()
{
	//std::cout << "dusman ucagh bb" << std::endl;
}

void DusmanUcak::hareketEt()
{
	m_konum += m_hiz;
}
