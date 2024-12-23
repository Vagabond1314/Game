#pragma once
#include <SFML/Graphics.hpp>
#include "ResourceManager.h"
#include <iostream>
#include "GameMap.h"

class Player
{
public:
    Player(ResourceManager& resourceManager, DoorManager& doorManager);

    void initialization(ResourceManager& resourceManager);

    void updateAnchors();

    sf::Vector2f getLeftAnchor() const;

    sf::Vector2f getRightAnchor() const;

    void handleInput(ResourceManager& resourceManager, GameMap& gameMap);

    void checkTileCollision(const GameMap& gameMap);

    void repelPlayer();

    void update(const sf::Vector2f& direction, ResourceManager& resourceManager);

    void draw(sf::RenderWindow& window);

    void setPosition(sf::Vector2f position);

    sf::Vector2f getPosition();

    sf::Sprite& getSprite();

private:
    const int spriteHeight = 210;
    const int spriteWidth = 208;
    int frameIndex = 0;
    int frameCount = 11;
    sf::Vector2f framePosition = { 0, 0 };
    sf::Vector2f previousPosition;
    sf::Sprite sprite;      // Спрайт гравця
    sf::Vector2f leftAnchor;   // Лівий якір
    sf::Vector2f rightAnchor;  // Правий якір

    ResourceManager& resourceManager;
    DoorManager& doorManager;
    sf::Texture texture;
    sf::Texture textureUp;
    sf::Texture textureDown;
    sf::Texture textureRight;
    sf::Texture textureLeft;
    float speed = 0.1f;     // Швидкість руху гравця
    sf::Clock spriteAnimationClock;
    sf::Time spriteFrameTimeInterval = sf::seconds(0.05);
};

