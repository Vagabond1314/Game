//#include "Game.h"
//
//int main() {
//	Game game;
//	game.run();
//}

//#include <SFML/Graphics.hpp>
//#include "Renderer.h"
//#include "Game.h"
//
//int main() {
//    // ��������� ����
//    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");
//    Game game(window);
//    // �������� ����
//    while (window.isOpen()) {
//        sf::Event event;
//
//        // ������� ����
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed) {
//                window.close();  // �������� ���� ��� �������� ��䳿 ��������
//            }
//        }
//        game.run();
//        // �������� ���� ����� ����������
//        //window.clear(sf::Color::Black);  // ���� ����
//
//        // ��� ����� �������� ��'���� (���������, ������, �������� ����)
//        //Renderer rend;
//        //rend.draw(window);
//        // ��������� ������������ ��'����
//        window.display();
//    }
//
//    return 0;
//}

#include "GameBoot.h"

int main() {
	GameBoot game;

	while (game.isRunning()) {
		game.handleInput();
		game.render();
		game.update();
	}
	int i = 1;
}

//using namespace std;
//
//int main() {
//    const int size = 50;
//    int matrix[size][size];
//
//    // ���������� ��� ������� ������
//    for (int i = 0; i < size; ++i) {
//        for (int j = 0; j < size; ++j) {
//            matrix[i][j] = 0;
//        }
//    }
//
//    // ���������� ������, ������� �� ����� ����� ���������
//    for (int i = 0; i < size; ++i) {
//        matrix[0][i] = 1;  // ������ �����
//        matrix[size - 1][i] = 1;  // ������� �����
//        matrix[i][0] = 1;  // ������ �������� (���� ��)
//        matrix[i][size - 1] = 1;  // ������� �������� (������ ��)
//    }
//
//    // �������� ������� �� �����
//    for (int i = 0; i < size; ++i) {
//        for (int j = 0; j < size; ++j) {
//            cout << matrix[i][j] << ", ";
//        }
//        cout << endl;
//    }
//
//    return 0;
//}

//#include <iostream>
//
//int isOdd(int numbers[], int count) {
//	int sum = 0;
//
//	for (int i = 0; i < count; i++) {
//		sum += numbers[i];
//	}
//
//	if (sum % 2 == 0) {
//		return 1;
//	}
//	else
//		return 0;
//}
//
//int main() {
//	int numbers[] = { 2, 3, 4, 5, 6, 7 };
//
//	int n = sizeof(numbers) / sizeof(numbers[0]);
//
//	if (isOdd(numbers, n)) 
//		std::cout << "Odd";
//	else
//		std::cout << "Not odd";
//}