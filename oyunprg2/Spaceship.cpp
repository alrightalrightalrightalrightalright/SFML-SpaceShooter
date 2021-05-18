#include "Spaceship.hpp"
#include "Onbellek.hpp"
#include "NesneYonetici.hpp"


Spaceship::Spaceship()
	:Animatable(8,assets_loc+"uzay\\user\\", sf::IntRect(25, 31, 448, 477)){
	m_konum = sf::Vector2f(320, 250);
	m_hiz = sf::Vector2f(9, 0);
	m_kalanCan = 1;

	sf::String secili = "1";
	olustur("uzay\\user\\" + secili, sf::IntRect(25, 31, 448, 477));
	auto aeah = m_sprite.getGlobalBounds();
	float scaleY = 1/(m_sprite.getGlobalBounds().width / 50);//hedef yükseklik
	float scaleX = 1/(m_sprite.getGlobalBounds().height / 50);//hedef yükseklik

	m_sprite.scale(sf::Vector2f(scaleY, scaleX));

	m_cerceveIndex = 0;
	m_atesEtmeCD = 5;

}

void Spaceship::atesEt() {
	if (m_cerceveIndex >= m_atesEtmeCD) {

		Mermi* yeniMermi =new Mermi(*Onbellek::getInstance().m_oyuncuMermi);//new Mermi();
		float xHizalama = (getSpriteBounds().width
			- yeniMermi->getSpriteBounds().width) / 2 ;
		yeniMermi->setKonum(getKonum() + sf::Vector2f(xHizalama, -10));

		static NesneYonetici& oyunmotoru = NesneYonetici::getInstance();
		oyunmotoru.m_mermiler.push_back(yeniMermi);

		m_cerceveIndex = 0;
	}
}

void Spaceship::HaritadanCikti()
{
	std::cout << "UZAY GEMÝSÝ MAPTEN CITKTII" << std::endl;

}



//uzay gemisinin yarýsý harita dýþýna çýkabilsin
//cizilebilir'de yartastiMi þeklinde bir tasarým yapýlabilir
//veya yarý taþma için hareketEt() çarðýmýnda taþma denemesi yapýlabilir diðerinde hareket et
void Spaceship::hareketEt()
{
	
	sf::Vector2f tasmaLimit=sf::Vector2f( m_sprite.getGlobalBounds().width/2,
		m_sprite.getGlobalBounds().height/2) ;//(25,25)
	sf::Vector2f artis;	
	artis =	_hareketEt();//get artýþ vektörü gibi

	Cizilebilir::hareketEt();

	//pencereden taþma kontrol
	//bug: köþelerde hýzlý takýlarak atlýyor
	if (m_konum.x + tasmaLimit.x <= 0) //sol
		m_konum.x= -tasmaLimit.x +3;//neden 3?	
	if (m_konum.y + tasmaLimit.y <= 0) //üst
		m_konum -= artis;
	if (m_konum.x + tasmaLimit.x > m_pencereBoyutlari.x) //sað
		m_konum.x = m_pencereBoyutlari.x - tasmaLimit.x +3;
	if (m_konum.y + tasmaLimit.y >= m_pencereBoyutlari.y) //alt
		m_konum -= artis;

}

