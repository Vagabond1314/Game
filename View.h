#ifndef VIEW_HPP
#define VIEW_HPP

#include <SFML/Graphics.hpp>

class View {
public:
    // �����������, ������ ����� ���� �� ����� "�������" (������ ������)
    View(const sf::Vector2f& windowSize, const sf::Vector2f& mapSize);

    // ������� ��������� ���� ��������� ������� �� ��������� ������
    void update(const sf::Sprite& player);

    // ������� ��'��� ��������� ��� ������������ ����
    const sf::View& getView() const;

private:
    sf::View view; // ��'��� ���������
    sf::Vector2f mapSize;
};

#endif // VIEW_HPP


