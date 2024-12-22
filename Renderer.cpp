#include "Renderer.h"

void Renderer::render(sf::RenderWindow& window, Player& player)
{
    //window.clear(sf::Color(92, 140, 43, 255));
    player.draw(window);
}

void Renderer::renderMenu(sf::RenderWindow& window, Menu& menu)
{
    window.clear(sf::Color(140, 55, 38, 255));
    menu.draw(window);
}

void Renderer::renderMap(sf::RenderWindow& window, GameMap& map)
{
    window.draw(map);
}
