#include "ResourceManager.h"
#include <stdexcept>

void ResourceManager::loadTexturesofPlayer() {
    // Створюємо тимчасову текстуру
    sf::Texture texture;

    // Завантажуємо і зберігаємо кожну текстуру
    if (texture.loadFromFile("Files\\PlayerImages\\Право.png")) {
        texturesofPlayer.push_back(texture);
    }
    else {
        std::cerr << "Не вдалося завантажити текстуру Право" << std::endl;
    }

    if (texture.loadFromFile("Files\\PlayerImages\\Верх.png")) {
        texturesofPlayer.push_back(texture);
    }
    else {
        std::cerr << "Не вдалося завантажити текстуру Верх" << std::endl;
    }

    if (texture.loadFromFile("Files\\PlayerImages\\Низ.png")) {
        texturesofPlayer.push_back(texture);
    }
    else {
        std::cerr << "Не вдалося завантажити текстуру Низ" << std::endl;
    }

    if (texture.loadFromFile("Files\\PlayerImages\\Ліво.png")) {
        texturesofPlayer.push_back(texture);
    }
    else {
        std::cerr << "Не вдалося завантажити текстуру Ліво" << std::endl;
    }
}

const sf::Texture& ResourceManager::getTextureofPlayer(size_t index) const {
    // Перевіряємо, чи індекс в допустимому діапазоні
    if (index >= texturesofPlayer.size()) {
        throw std::out_of_range("Текстура з індексом " + std::to_string(index) + " не знайдена.");
    }
    return texturesofPlayer[index];
}

//void ResourceManager::loadTexturesofMenu()
//{
//    // Завантажуємо і зберігаємо кожну текстуру
//    sf::Texture texture;
//
//    if (texture.loadFromFile("G:\\C++\\App\\App\\App\\Files\\GUIimages\\zh3yXb-play-button-png-image-free-download-searchpng.png")) {
//        texturesofMenu.push_back(std::move(texture)); // Додаємо текстуру у вектор
//    }
//    else {
//        std::cerr << "Не вдалося завантажити текстуру Право" << std::endl;
//    }
//
//    if (texture.loadFromFile("G:\\C++\\App\\App\\App\\Files\\GUIimages\\zh3yXb-play-button-png-image-free-download-search1png.png")) {
//        texturesofMenu.push_back(std::move(texture));
//    }
//    else {
//        std::cerr << "Не вдалося завантажити текстуру Верх" << std::endl;
//    }
//
//    if (texture.loadFromFile("G:\\C++\\App\\App\\App\\Files\\GUIimages\\901827-200.png")) {
//        texturesofMenu.push_back(std::move(texture));
//    }
//    else {
//        std::cerr << "Не вдалося завантажити текстуру Низ" << std::endl;
//    }
//
//    if (texture.loadFromFile("G:\\C++\\App\\App\\App\\Files\\GUIimages\\901827-2001.png")) {
//        texturesofMenu.push_back(std::move(texture));
//    }
//    else {
//        std::cerr << "Не вдалося завантажити текстуру Ліво" << std::endl;
//    }
//
//    if (texture.loadFromFile("G:\\C++\\App\\App\\App\\Files\\GUIimages\\resumeButton.png")) {
//        texturesofMenu.push_back(std::move(texture));
//    }
//    else {
//        std::cerr << "Не вдалося завантажити текстуру Низ" << std::endl;
//    }
//
//    if (texture.loadFromFile("G:\\C++\\App\\App\\App\\Files\\GUIimages\\resumeButtonPressed.png")) {
//        texturesofMenu.push_back(std::move(texture));
//    }
//    else {
//        std::cerr << "Не вдалося завантажити текстуру Ліво" << std::endl;
//    }
//}

void ResourceManager::loadTexturesofMenu()
{
    // Завантажуємо і зберігаємо кожну текстуру
    sf::Texture texture;

    if (texture.loadFromFile("Files\\GUIimages\\zh3yXb-play-button-png-image-free-download-searchpng.png")) {
        textures[0] = (std::move(texture)); // Додаємо текстуру у вектор
    }
    else {
        std::cerr << "Не вдалося завантажити текстуру Право" << std::endl;
    }

    if (texture.loadFromFile("Files\\GUIimages\\zh3yXb-play-button-png-image-free-download-search1png.png")) {
        textures[1] = (std::move(texture)); // Додаємо текстуру у вектор
    }
    else {
        std::cerr << "Не вдалося завантажити текстуру Верх" << std::endl;
    }

    if (texture.loadFromFile("Files\\GUIimages\\901827-200.png")) {
        textures[2] = (std::move(texture)); // Додаємо текстуру у вектор
    }
    else {
        std::cerr << "Не вдалося завантажити текстуру Низ" << std::endl;
    }

    if (texture.loadFromFile("Files\\GUIimages\\901827-2001.png")) {
        textures[3] = (std::move(texture)); // Додаємо текстуру у вектор
    }
    else {
        std::cerr << "Не вдалося завантажити текстуру Ліво" << std::endl;
    }

    if (texture.loadFromFile("Files\\GUIimages\\resumeButton.png")) {
        textures[4] = (std::move(texture)); // Додаємо текстуру у вектор
    }
    else {
        std::cerr << "Не вдалося завантажити текстуру Низ" << std::endl;
    }

    if (texture.loadFromFile("Files\\GUIimages\\resumeButtonPressed.png")) {
        textures[5] = (std::move(texture)); // Додаємо текстуру у вектор
    }
    else {
        std::cerr << "Не вдалося завантажити текстуру Ліво" << std::endl;
    }

    if (texture.loadFromFile("Files\\GUIimages\\exitButton.png")) {
        textures[6] = (std::move(texture)); // Додаємо текстуру у вектор
    }
    else {
        std::cerr << "Не вдалося завантажити текстуру Ліво" << std::endl;
    }

    if (texture.loadFromFile("Files\\GUIimages\\exitButtonPressed.png")) {
        textures[7] = (std::move(texture)); // Додаємо текстуру у вектор
    }
    else {
        std::cerr << "Не вдалося завантажити текстуру Ліво" << std::endl;
    }
}

const sf::Texture& ResourceManager::getTextureofMenu(size_t index) const
{
    return textures[index];
}

void ResourceManager::loadMapTextures()
{
    // Завантажуємо і зберігаємо кожну текстуру
    sf::Texture texture;

    if (texture.loadFromFile("Files\\MapImages\\Ground.png")) {
        texturesofMap[0] = (std::move(texture)); // Додаємо текстуру у вектор
    }
    else {
        std::cerr << "Не вдалося завантажити текстуру Право" << std::endl;
    }

    if (texture.loadFromFile("Files\\MapImages\\road.png")) {
        texturesofMap[1] = (std::move(texture)); // Додаємо текстуру у вектор
    }
    else {
        std::cerr << "Не вдалося завантажити текстуру Право" << std::endl;
    }

    if (texture.loadFromFile("Files\\MapImages\\wall.png")) {
        texturesofMap[2] = (std::move(texture)); // Додаємо текстуру у вектор
    }
    else {
        std::cerr << "Не вдалося завантажити текстуру Право" << std::endl;
    }
}

const sf::Texture& ResourceManager::getTextureofMap(size_t index) const
{
    return texturesofMap[index];
}




