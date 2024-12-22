#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "ResourceManager.h" // Для доступу до ресурсів
#include "View.h"

class GameMap : public sf::Drawable {
public:
    GameMap(ResourceManager& resourceManager);

    int* loadGameMapfromtxt(const std::string& filename);

    void createGameMap();

    bool generateMap(const std::string& tileset, int* tiles, unsigned int width, unsigned int height);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    int getTileIndex(const sf::Sprite& player) const;

    const sf::Texture* getPlayerTileTexture(const sf::Sprite& player) const;

    void addWallTile(int tileIndex);

    bool isWallTile(int tileIndex) const;

private:
    ResourceManager& resourceManager;
    int rows;
    int cols;
    sf::Vector2f tileSize = { 16, 16 };
    sf::VertexArray vertexArray;
    sf::Sprite mapSprites[3300];
    sf::Texture texture1;
    sf::Sprite sprite;
    sf::VertexArray m_vertices;  // Масив вершин для тайлів
    sf::Texture m_tileset;       // Тайлсет

    //View gameview;
    sf::Texture texture;
    std::vector<const sf::Texture*> tileTextures;
    std::vector<int> wallTiles; // Вектор для зберігання індексів тайлів-стін
};

#endif // GAMEMAP_H
