#include "EventControl.hpp"
#include <iostream>

EventControl::EventControl(sf::RenderWindow& window)
	:m_window(window)
{
}

void EventControl::bepseafei()
{
	while (m_window.pollEvent(event))
	{
		std::cout << "event: " << event.key.code << std::endl;
		if (event.type == sf::Event::Closed)
			m_window.close();
		if (event.type == sf::Event::KeyPressed) {
			std::cout << "key basýldý aga" << event.key.code << std::endl;

		}
	}
}
