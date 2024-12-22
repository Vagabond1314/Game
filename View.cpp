#include "View.h"

View::View(const sf::Vector2f& windowSize, const sf::Vector2f& mapSize) {
    // Ініціалізуємо погляд з розміром вікна
    view.setSize(windowSize);
    view.setCenter(windowSize.x / 2.0f, windowSize.y / 2.0f);

    // Зберігаємо розміри карти
    this->mapSize = mapSize;
}

void View::update(const sf::Sprite& player) {
    // Отримуємо позицію гравця
    sf::Vector2f playerPosition = player.getPosition();

    // Обмежуємо рух погляду так, щоб не виходити за межі карти
    sf::Vector2f halfSize = view.getSize() / 2.0f;

    float viewX = playerPosition.x;
    float viewY = playerPosition.y;

    // Перевірка по X
    if (playerPosition.x - halfSize.x < 0) {
        viewX = halfSize.x; // Ліва межа
    }
    else if (playerPosition.x + halfSize.x > mapSize.x) {
        viewX = mapSize.x - halfSize.x; // Права межа
    }

    // Перевірка по Y
    if (playerPosition.y - halfSize.y < 0) {
        viewY = halfSize.y; // Верхня межа
    }
    else if (playerPosition.y + halfSize.y > mapSize.y) {
        viewY = mapSize.y - halfSize.y; // Нижня межа
    }

    // Встановлюємо центр погляду з урахуванням меж
    view.setCenter(viewX, viewY);
}

const sf::View& View::getView() const {
    return view;
}


