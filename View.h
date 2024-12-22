#ifndef VIEW_HPP
#define VIEW_HPP

#include <SFML/Graphics.hpp>

class View {
public:
    // Конструктор, приймає розмір вікна та розмір "погляду" (видимої області)
    View(const sf::Vector2f& windowSize, const sf::Vector2f& mapSize);

    // Оновлює положення вікна перегляду залежно від положення гравця
    void update(const sf::Sprite& player);

    // Повертає об'єкт перегляду для встановлення вікну
    const sf::View& getView() const;

private:
    sf::View view; // Об'єкт перегляду
    sf::Vector2f mapSize;
};

#endif // VIEW_HPP


