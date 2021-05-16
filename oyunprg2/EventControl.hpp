#pragma once

#include<SFML/Graphics.hpp>
class EventControl
{
	
public:
	EventControl(sf::RenderWindow& window);
	void bepseafei();
	sf::Event event;	
	
	sf::RenderWindow& m_window;

};

