#include "View.h"

View::View(const sf::Vector2f& windowSize, const sf::Vector2f& mapSize) {
    // ���������� ������ � ������� ����
    view.setSize(windowSize);
    view.setCenter(windowSize.x / 2.0f, windowSize.y / 2.0f);

    // �������� ������ �����
    this->mapSize = mapSize;
}

void View::update(const sf::Sprite& player) {
    // �������� ������� ������
    sf::Vector2f playerPosition = player.getPosition();

    // �������� ��� ������� ���, ��� �� �������� �� ��� �����
    sf::Vector2f halfSize = view.getSize() / 2.0f;

    float viewX = playerPosition.x;
    float viewY = playerPosition.y;

    // �������� �� X
    if (playerPosition.x - halfSize.x < 0) {
        viewX = halfSize.x; // ˳�� ����
    }
    else if (playerPosition.x + halfSize.x > mapSize.x) {
        viewX = mapSize.x - halfSize.x; // ����� ����
    }

    // �������� �� Y
    if (playerPosition.y - halfSize.y < 0) {
        viewY = halfSize.y; // ������ ����
    }
    else if (playerPosition.y + halfSize.y > mapSize.y) {
        viewY = mapSize.y - halfSize.y; // ����� ����
    }

    // ������������ ����� ������� � ����������� ���
    view.setCenter(viewX, viewY);
}

const sf::View& View::getView() const {
    return view;
}


