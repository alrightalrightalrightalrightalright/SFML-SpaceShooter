#include "Cizilebilir.hpp"


Cizilebilir::Cizilebilir() {
	//:m_pencere(pencere){// WAY BABANIN GEMÜÐÜNE

//	m_konum = sf::Vector2f(320, 250);
	//m_hiz = sf::Vector2f(5, 0);
//	olustur();

	m_haritaDisindaMi = false;
}

sf::Vector2f Cizilebilir::getKonum() {
	return m_konum;
}
void Cizilebilir::setKonum(sf::Vector2f konum) {
	m_konum = konum;
}

sf::Vector2f Cizilebilir::getHiz() {
	return m_hiz;
}
bool Cizilebilir::haritaDisindaMi(){return m_haritaDisindaMi;}

void Cizilebilir::setHiz(sf::Vector2f hiz) {
	m_hiz = hiz;
}



//hareket etme implement
sf::Vector2f Cizilebilir::_hareketEt() {
	sf::Vector2f artis;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		artis += sf::Vector2f(m_hiz.x, 0);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		artis += sf::Vector2f(-m_hiz.x, 0);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		artis += sf::Vector2f(0, -m_hiz.x);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		artis += sf::Vector2f(0, m_hiz.x);

	return artis;
}

void Cizilebilir::hareketEt() {
	m_konum += _hareketEt();
}



void Cizilebilir::olustur() {
	sf::String dosyaAdi = "error";
	m_kaplama.loadFromFile(assets_loc + dosyaAdi + ".png");
	m_sprite.setTexture(m_kaplama);


	//m_sprite.setScale(0.25f, 0.25f);
}

/*params:
dosya: resmin partial pathý
area: resmin kullanýlacak bölümü*/
void Cizilebilir::olustur(sf::String dosya, sf::IntRect area, sf::Vector2f scale) {
	m_kaplama.loadFromFile(assets_loc + dosya + ".png", area);
	m_sprite.setTexture(m_kaplama);
	m_sprite.setScale(scale);
}

//konum + en,boy
sf::FloatRect Cizilebilir::getSpriteBounds() {
	return m_sprite.getGlobalBounds();
}
void Cizilebilir::HaritadanCikti()
{
	std::cout << "DEFAULT MAPTEN CIKMA FUNC" << std::endl;


}
void Cizilebilir::tasmaKontrol() {
	auto spriteKonum = m_konum;
	auto pencereBoyut = m_pencereBoyutlari;// window.getSize();

	auto aegea = m_sprite.getGlobalBounds();

	//TAM TAÞMA KONTROL: sprite tamamen haritadan çýkmýþ mý
	if (spriteKonum.x + getSpriteBounds().width <= 0) //sol
		m_haritaDisindaMi = true;
	else if (spriteKonum.y + getSpriteBounds().height <= 0) //üst
		m_haritaDisindaMi = true;
	else if (spriteKonum.x >= pencereBoyut.x) //sað
		m_haritaDisindaMi = true;
	else if (spriteKonum.y >= pencereBoyut.y) //alt
		m_haritaDisindaMi = true;
	else
		m_haritaDisindaMi = false;

	if (m_haritaDisindaMi) HaritadanCikti();
}

void Cizilebilir::ciz(sf::RenderWindow& window)
{
	m_pencereBoyutlari = window.getSize();//BAÞKA YERDE ATANMIYOR, MUHTEMEL BUG!

	m_sprite.setPosition(m_konum);
	window.draw(m_sprite);
	tasmaKontrol();
}