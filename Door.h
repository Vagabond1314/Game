#include <SFML/Graphics.hpp>
#include <string>

class Door {
private:
    //sf::Sprite sprite;          // Спрайт дверей
    //sf::Texture textureLocked;  // Текстура зачинених дверей
    //sf::Texture textureUnlocked;// Текстура відчинених дверей
    //sf::FloatRect bounds;       // Зона взаємодії
    std::string targetRoom;     // Назва кімнати, куди ведуть двері
    bool isLocked;              // Статус замкненості
    int tile;

public:
    // Конструктор
    Door(int tile, const std::string& targetRoom, bool locked = false)
        : tile(tile), targetRoom(targetRoom), isLocked(locked) {
        // Завантажуємо текстури
        //if (!textureLocked.loadFromFile(lockedTexturePath)) {
        //    throw std::runtime_error("Failed to load locked door texture");
        //}
        //if (!textureUnlocked.loadFromFile(unlockedTexturePath)) {
        //    throw std::runtime_error("Failed to load unlocked door texture");
        //}

        // Налаштовуємо спрайт
        //sprite.setTexture(isLocked ? textureLocked : textureUnlocked);
        //sprite.setPosition(position);

        // Встановлення області взаємодії
        //bounds = sprite.getGlobalBounds();
    }

    // Метод для перевірки взаємодії з гравцем
    //bool checkInteraction(const sf::FloatRect& playerBounds) const {
    //    return bounds.intersects(playerBounds) && !isLocked;
    //}

    // Метод для відкривання дверей
    void unlock() {
        isLocked = false;
    }

    // Метод для закривання дверей
    void lock() {
        isLocked = true;
    }

    // Метод для отримання назви кімнати
    std::string getTargetRoom() const {
        return targetRoom;
    }

    int getTile() {
        return tile;
    }

    // Метод для рендерингу дверей
    //void render(sf::RenderWindow& window) {
    //    window.draw(sprite);
    //}

    // Метод для отримання статусу дверей
    bool getLockStatus() const {
        return isLocked;
    }
};
