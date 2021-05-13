#include "Top.hpp"
#include "Ortak.hpp"


static const char* toplar[] = { 
"ball_blue",
"ball_green",
"ball_orange",
"ball_red",
"ball_silver",
"ball_yellow"
};

Top::Top() {
	m_konum = sf::Vector2f(120, 150);
	m_hizv= sf::Vector2f(4,4);
	m_yon = sf::Vector2i(1, 1);
	m_hareketEdiyor = false;
	m_yonetilebilir = true;
	olustur();
}
void Top::setKonum(sf::Vector2f konum) {
	m_konum = konum;
}
void Top::setHareketEdiyor(bool deger) { m_hareketEdiyor = deger; }
sf::Vector2f Top::getKonum() { return m_konum; }

void Top::setYonetilebilir(bool deger) { m_yonetilebilir = deger; }
void Top::setPadHiz(sf::Vector2f hiz) { m_pad_hiz = hiz; }
 
//vektör çarpýmý:https://stackoverflow.com/a/44079870/14321951
template<typename TLeft, typename TRight>
inline auto carp(const sf::Vector2<TLeft>& lhs, const sf::Vector2<TRight>& rhs) {
	return sf::Vector2<std::common_type_t<TLeft, TRight>>(lhs.x * rhs.x, lhs.y * rhs.y);
}


void Top::hareketEt() {
//	if (!m_hareketEdiyor)return;

	sf::Vector2f artis;
	artis = m_hizv;

	if (m_yonetilebilir) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			artis = sf::Vector2f(m_pad_hiz.x, 0);
			m_konum += artis;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			artis = sf::Vector2f(-m_pad_hiz.x, 0);
			m_konum += artis;
		}
		return;
	}


	artis  = carp(artis,m_yon);

	m_konum += m_hizv;


}

void Top::olustur() {
	sf::String secili = toplar[rand() % 6];

	m_kaplama.loadFromFile(assets_loc+"Balls\\"+ secili +".png");
	m_sprite.setTexture(m_kaplama);
	m_sprite.setScale(0.05f, 0.05f);
}

void Top::ciz(sf::RenderWindow& pencere)
{
	m_sprite.setPosition(m_konum); // absolute position
	pencere.draw(m_sprite);

}