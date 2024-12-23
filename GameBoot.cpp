#include "GameBoot.h"

GameBoot::GameBoot() : window(windowSize, windowTitle, sf::Style::Fullscreen), player(resourceManager, doorManager), menu(resourceManager, gameState),
gameView(sf::Vector2f(window.getSize()), sf::Vector2f(2800, 2800)), gameMap(resourceManager), doorManager(gameDoors) {
    doorInitialization();
}

bool GameBoot::isRunning() const
{
    return isRunningBool;
}

//void Game::run() {
//    while (window.isOpen()) {
//        handleInput();
//        update();
//        render();               // Відображаємо все
//    }
//}

void GameBoot::handleInput() {
    sf::Event event;
    //std::cout << gameState.getState() << std::endl;
    while (window.pollEvent(event)) {
        if (gameState.getState() == "Menu" || gameState.getState() == "GameStart") {
            // Якщо меню активне, обробляємо події для меню
            menu.handleInput(window, event);
            // Додаємо перевірку на натискання клавіші Escape в меню
            if (!(gameState.getState() == "GameStart"))
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                    gameState.setState("Playing");
                }
        }
        else {
            // Якщо меню неактивне, обробляємо події для гри
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                switch (event.key.code) {
                case sf::Keyboard::Escape:
                    gameState.setState("Menu");
                    break;
                }
                break;
            }
        }
    }
}

void GameBoot::update()
{
    //player.update(playerDirection, resourceManager);
    if (!(gameState.getState() == "Menu" || gameState.getState() == "GameStart")) {
        player.handleInput(resourceManager, gameMap);
    }
    gameView.update(player.getSprite());
    player.checkTileCollision(gameMap);
}

bool GameBoot::doorInitialization()                                                                 
{
    gameDoors = {
    Door(43, "BartoWorld", false),
    Door(150, "WorldtoBar", false)
    };
    std::cout << "Doors succesfully initialized" << std::endl;
    return false;
}

void GameBoot::render()
{
    window.clear();
    
    if (gameState.getState() == "Playing") {
        window.setView(gameView.getView());
        renderer.renderMap(window, gameMap);
        int tileIndex = gameMap.getTileIndex(player.getSprite());
        std::cout << "Current Tile: " << tileIndex << std::endl;

    }

    if ((gameState.getState() == "Menu") || (gameState.getState() == "GameStart"))
        window.setView(window.getDefaultView());

    renderer.render(window, player);

    if ((gameState.getState() == "Menu") || (gameState.getState() == "GameStart"))
        renderer.renderMenu(window, menu);

    window.display();
}

