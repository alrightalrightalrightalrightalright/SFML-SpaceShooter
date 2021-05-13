#include "Pad.hpp"
static const char* padler[] = {
"bat_blue",
"bat_black",
"bat_orange",
"bat_pink",
"bat_yellow"
};
 Pad::Pad()  {
	 m_konum = sf::Vector2f(320, 250);
	 m_hiz = sf::Vector2f(9, 0);

	 sf::String secili = padler[rand() % 5];
	 olustur("Bats\\"+secili, sf::IntRect(25, 179, 463, 101));

}


