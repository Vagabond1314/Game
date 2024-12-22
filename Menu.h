#pragma once
#include "ResourceManager.h"
#include "GameStateManager.h"

class Menu
{
public:
	Menu(ResourceManager& resourceManager, GameStateManager& gameState);

	void initializationMenu(ResourceManager& resourceManager);

	void run();

	bool isRunning() const;

	void handleInput(sf::RenderWindow& window, sf::Event& event);

	void draw(sf::RenderWindow& window);

private:
	GameStateManager& gameState;
	bool menuIsRunningBool = true;
	sf::Texture playButtonPressed;
	sf::Texture settingsButtonPressed;
	sf::Texture resumeButtonPressed;
	sf::Texture exitButtonPressed;
	sf::Texture playButtonTex;
	sf::Texture settingsButtonTex;
	sf::Texture resumeButtonTex;
	sf::Texture exitButtonTex;
	sf::Sprite playButton;
	sf::Sprite settingsButton;
	sf::Sprite resumeButton;
	sf::Sprite exitButton;
};

