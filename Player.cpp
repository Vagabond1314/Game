#include "Player.h"
#include "GameMap.h"

Player::Player(ResourceManager& resourceManager) :
    resourceManager(resourceManager)
{
    initialization(resourceManager);
}

void Player::initialization(ResourceManager& resourceManager) {
    // Завантажуємо текстури
    resourceManager.loadTexturesofPlayer();
    textureRight = resourceManager.getTextureofPlayer(0);
    textureUp = resourceManager.getTextureofPlayer(1);
    textureDown = resourceManager.getTextureofPlayer(2);
    textureLeft = resourceManager.getTextureofPlayer(3);
    // Встановлюємо текстуру за замовчуванням (рух вниз)
    sprite.setTexture(textureDown); // textureDown
    sprite.setTextureRect(sf::IntRect(framePosition.x, framePosition.y, spriteWidth, spriteHeight));
    sprite.setScale(1, 1);
    sprite.setPosition(150, 150); // Початкова позиція
    sprite.setOrigin(105, 130);
}

void Player::handleInput(ResourceManager& resourceManager, GameMap& gameMap) {
    // Рухаємо гравця
    previousPosition = sprite.getPosition();
    sf::Vector2f position = sprite.getPosition();

    sf::Time elapsedTime = spriteAnimationClock.getElapsedTime();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        sprite.setPosition(position + sf::Vector2f(0, -speed)); // Рух вгору
        sprite.setTexture(textureUp);

        // Перевірка часу для оновлення кадрів
        if (elapsedTime > spriteFrameTimeInterval) {
            spriteAnimationClock.restart();

            frameIndex++;
            if (frameIndex >= frameCount) {
                frameIndex = 0; // Скидання до першого кадру
            }

            // Оновлення текстурного прямокутника
            sprite.setTextureRect(sf::IntRect(frameIndex * spriteWidth, 0, spriteWidth, spriteHeight)); // Використання frameIndex
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {

        sprite.setPosition(position + sf::Vector2f(0, speed));
        sprite.setTexture(textureDown);

        // Перевірка часу для оновлення кадрів
        if (elapsedTime > spriteFrameTimeInterval) {
            spriteAnimationClock.restart();

            frameIndex++;
            if (frameIndex >= frameCount) {
                frameIndex = 0; // Скидання до першого кадру
            }

            // Оновлення текстурного прямокутника
            sprite.setTextureRect(sf::IntRect(frameIndex * spriteWidth, 0, spriteWidth, spriteHeight)); // Використання frameIndex
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {

        sprite.setPosition(position + sf::Vector2f(-speed, 0));
        sprite.setTexture(textureLeft);

        // Перевірка часу для оновлення кадрів
        if (elapsedTime > spriteFrameTimeInterval) {
            spriteAnimationClock.restart();

            frameIndex++;
            if (frameIndex >= frameCount) {
                frameIndex = 0; // Скидання до першого кадру
            }

            // Оновлення текстурного прямокутника
            sprite.setTextureRect(sf::IntRect(frameIndex * spriteWidth, 0, spriteWidth, spriteHeight)); // Використання frameIndex
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {

        sprite.setPosition(position + sf::Vector2f(speed, 0));
        sprite.setTexture(textureRight);

        // Перевірка часу для оновлення кадрів
        if (elapsedTime > spriteFrameTimeInterval) {
            spriteAnimationClock.restart();

            frameIndex++;
            if (frameIndex >= frameCount) {
                frameIndex = 0; // Скидання до першого кадру
            }

            // Оновлення текстурного прямокутника
            sprite.setTextureRect(sf::IntRect(frameIndex * spriteWidth, 0, spriteWidth, spriteHeight)); // Використання frameIndex
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
        unsigned int rows = 50;
        unsigned int cols = 10;
        if (gameMap.getTileIndex(sprite) == 46) {
            gameMap.generateMap("Files\\MapImages\\GroundandRoad.png", gameMap.loadGameMapfromtxt("Files\\MapsData\\world.txt"), rows , rows); 
        }
        if (gameMap.getTileIndex(sprite) == 259) {
            gameMap.generateMap("Files\\MapImages\\GroundandRoad.png", gameMap.loadGameMapfromtxt("Files\\MapsData\\Bar.txt"), cols, cols);
        }
    }

}

// Метод для перевірки поточного тайла, де знаходиться гравець
void Player::checkTileCollision(const GameMap& gameMap) {
    // Отримуємо індекс тайла, на якому знаходиться гравець
    int currentTileIndex = gameMap.getTileIndex(sprite);

    if (gameMap.isWallTile(currentTileIndex)) {
        // Якщо так, відштовхуємо гравця назад
        repelPlayer();
    }
}

void Player::repelPlayer() {
    // Повертаємо гравця на попередню позицію, тобто зупиняємо його рух
    sprite.setPosition(previousPosition);
}

void Player::update(const sf::Vector2f& direction, ResourceManager& resourceManager) {

}

void Player::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Player::setPosition(sf::Vector2f position) {
    sprite.setPosition(position);
}

sf::Vector2f Player::getPosition() {
    return sprite.getPosition();
}

sf::Sprite& Player::getSprite()
{
    return sprite;
}
