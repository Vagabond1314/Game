#include "EventManager.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Player.h"

void EventManager::handleInput(sf::RenderWindow& window, Player& player)
{
    sf::Vector2f position = player.getPosition();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        player.setPosition(position + sf::Vector2f(0, -1));
        //playerDirection.y = -1; // –ух вгору
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        //playerDirection.y = 1;  // –ух вниз
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        //playerDirection.x = -1; // –ух вл≥во
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        //playerDirection.x = 1;  // –ух вправо
    }
}
