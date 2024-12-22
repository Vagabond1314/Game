#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Player.h"

class EventManager
{
public:
	void handleInput(sf::RenderWindow& window, Player& player);

private:

};

