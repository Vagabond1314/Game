#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <array>
#include <iostream>
#include <vector>

class ResourceManager
{
public:

	void loadTexturesofPlayer();

	const sf::Texture& getTextureofPlayer(size_t index) const;

	void loadTexturesofMenu();

	const sf::Texture& getTextureofMenu(size_t index) const;

	void loadMapTextures();

	const sf::Texture& getTextureofMap(size_t index) const;

private:
	//std::map<std::string, sf::Texture> textures; // Мапа текстур
	sf::Texture textures[8];
	std::vector<sf::Texture> texturesofPlayer;
	sf::Texture texturesofMap[10];

	sf::Texture defaultTexture;                     // Текстура за замовчуванням
	// Мапа для зберігання текстур
};

