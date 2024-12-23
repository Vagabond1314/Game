#include <SFML/Graphics.hpp>
#include <string>

class Door {
private:
    //sf::Sprite sprite;          // ������ ������
    //sf::Texture textureLocked;  // �������� ��������� ������
    //sf::Texture textureUnlocked;// �������� ��������� ������
    //sf::FloatRect bounds;       // ���� �����䳿
    std::string targetRoom;     // ����� ������, ���� ������ ����
    bool isLocked;              // ������ ����������
    int tile;

public:
    // �����������
    Door(int tile, const std::string& targetRoom, bool locked = false)
        : tile(tile), targetRoom(targetRoom), isLocked(locked) {
        // ����������� ��������
        //if (!textureLocked.loadFromFile(lockedTexturePath)) {
        //    throw std::runtime_error("Failed to load locked door texture");
        //}
        //if (!textureUnlocked.loadFromFile(unlockedTexturePath)) {
        //    throw std::runtime_error("Failed to load unlocked door texture");
        //}

        // ����������� ������
        //sprite.setTexture(isLocked ? textureLocked : textureUnlocked);
        //sprite.setPosition(position);

        // ������������ ������ �����䳿
        //bounds = sprite.getGlobalBounds();
    }

    // ����� ��� �������� �����䳿 � �������
    //bool checkInteraction(const sf::FloatRect& playerBounds) const {
    //    return bounds.intersects(playerBounds) && !isLocked;
    //}

    // ����� ��� ���������� ������
    void unlock() {
        isLocked = false;
    }

    // ����� ��� ���������� ������
    void lock() {
        isLocked = true;
    }

    // ����� ��� ��������� ����� ������
    std::string getTargetRoom() const {
        return targetRoom;
    }

    int getTile() {
        return tile;
    }

    // ����� ��� ���������� ������
    //void render(sf::RenderWindow& window) {
    //    window.draw(sprite);
    //}

    // ����� ��� ��������� ������� ������
    bool getLockStatus() const {
        return isLocked;
    }
};
