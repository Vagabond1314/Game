#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Player.h"
#include "EventManager.h"
#include "Renderer.h"
#include "ResourceManager.h"
#include "Menu.h"
#include "GameStateManager.h"
#include "View.h"
#include "GameMap.h"

class GameBoot
{
public:
	GameBoot();

	bool isRunning() const;
	bool isGameActive();
	void makeGameActive();

	void run();
	void handleInput();
	void update();
	bool doorInitialization();
	void render();

private:
	bool isRunningBool = true;
	bool isMenuActive = true;
	bool isGameActiveBool = false;

	const sf::VideoMode windowSize = sf::VideoMode::getDesktopMode();
	const std::string windowTitle = "Game";
	sf::RenderWindow window;      // ³��� ���

	std::vector<Door> gameDoors;

	GameMap gameMap;
	View gameView;
	Menu menu;
	GameStateManager gameState;
	Player player;                // ��'��� ������
	EventManager eventManager;    // �������� ����
	Renderer renderer;            // �������� ����������
	ResourceManager resourceManager; // �������� �������
	DoorManager doorManager;
};

