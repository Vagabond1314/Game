#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Menu.h"
#include "GameMap.h"

class Renderer
{
public:
	void render(sf::RenderWindow& window, Player& player);

	void renderMenu(sf::RenderWindow& window, Menu& menu);

	void renderMap(sf::RenderWindow& window, GameMap& map);

private:

};

