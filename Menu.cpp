#include "Menu.h"
#include "GameBoot.h"
#include <iostream>

Menu::Menu(ResourceManager& resourceManager, GameStateManager& gameState) : gameState(gameState) {
    initializationMenu(resourceManager);
}

void Menu::initializationMenu(ResourceManager& resourceManager)
{
    resourceManager.loadTexturesofMenu();
    playButtonTex = resourceManager.getTextureofMenu(0);
    playButtonPressed = resourceManager.getTextureofMenu(1);
    settingsButtonTex = resourceManager.getTextureofMenu(2);
    settingsButtonPressed = resourceManager.getTextureofMenu(3);
    resumeButtonTex = resourceManager.getTextureofMenu(4);
    resumeButtonPressed = resourceManager.getTextureofMenu(5);
    exitButtonTex = resourceManager.getTextureofMenu(6);
    exitButtonPressed = resourceManager.getTextureofMenu(7);
    // Встановлюємо текстуру за замовчуванням (рух вниз)
    playButton.setTexture(playButtonTex);
    settingsButton.setTexture(settingsButtonTex);
    resumeButton.setTexture(resumeButtonTex);
    exitButton.setTexture(exitButtonTex);
    playButton.setPosition(800, 400); // Початкова позиція
    playButton.setScale(0.3, 0.3);
    settingsButton.setPosition(1000, 600); // Початкова позиція
    resumeButton.setPosition(100, 100);
    exitButton.setScale(0.3, 0.3);
    exitButton.setPosition(1000, 800);
}

void Menu::handleInput(sf::RenderWindow& window, sf::Event& event) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window); // Отримуємо позицію курсора

    // Оновлюємо стан кнопок в залежності від позиції курсора
    if (playButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
        playButton.setTexture(playButtonPressed);
    }
    else {
        playButton.setTexture(playButtonTex);
    }

    if (settingsButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
        settingsButton.setTexture(settingsButtonPressed);
    }
    else {
        settingsButton.setTexture(settingsButtonTex);
    }

    if (resumeButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
        resumeButton.setTexture(resumeButtonPressed);
    }
    else {
        resumeButton.setTexture(resumeButtonTex);
    }

    if (exitButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
        exitButton.setTexture(exitButtonPressed);
    }
    else {
        exitButton.setTexture(exitButtonTex);
    }

    // Обробка подій миші
    switch (event.type) {
    case sf::Event::MouseButtonPressed:
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (playButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                // Дії для початку гри
                gameState.setState("Playing");
            }

            if (settingsButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                // Дії для відкриття налаштувань
            }

            if (resumeButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                // Дії для відновлення гри
                gameState.setState("Playing");
            }

            if (exitButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                // Дії для відновлення гри
                if (gameState.getState() == "GameStart")
                    window.close();

                if (gameState.getState() == "Menu")
                    gameState.setState("GameStart");
            }
        }
        break;

    case sf::Event::MouseButtonReleased:
        // Кнопки повертаються до початкової текстури після відпускання кнопки миші
        playButton.setTexture(playButtonTex);
        settingsButton.setTexture(settingsButtonTex);
        resumeButton.setTexture(resumeButtonTex);
        break;

    case sf::Event::KeyPressed:
        // Тут також можна додати додаткові дії при натисканні клавіш, якщо потрібно
        break;
    }
}

void Menu::draw(sf::RenderWindow& window)
{
    if (gameState.getState() == "GameStart") {
        window.draw(settingsButton);
        window.draw(playButton);
        window.draw(exitButton);
    }
    if (gameState.getState() == "Menu") {
        window.draw(settingsButton);
        window.draw(resumeButton);
        window.draw(exitButton);
    }
}