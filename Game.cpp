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
//    // Створення вікна
//    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");
//    Game game(window);
//    // Основний цикл
//    while (window.isOpen()) {
//        sf::Event event;
//
//        // Обробка подій
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed) {
//                window.close();  // Закриття вікна при отриманні події закриття
//            }
//        }
//        game.run();
//        // Очищення вікна перед малюванням
//        //window.clear(sf::Color::Black);  // Колір фону
//
//        // Тут можна малювати об'єкти (наприклад, гравця, текстури тощо)
//        //Renderer rend;
//        //rend.draw(window);
//        // Виведення намальованих об'єктів
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
//    // Заповнюємо всю матрицю нулями
//    for (int i = 0; i < size; ++i) {
//        for (int j = 0; j < size; ++j) {
//            matrix[i][j] = 0;
//        }
//    }
//
//    // Заповнюємо перший, останній та бокові рядки одиницями
//    for (int i = 0; i < size; ++i) {
//        matrix[0][i] = 1;  // Перший рядок
//        matrix[size - 1][i] = 1;  // Останній рядок
//        matrix[i][0] = 1;  // Перший стовпець (лівий бік)
//        matrix[i][size - 1] = 1;  // Останній стовпець (правий бік)
//    }
//
//    // Виводимо матрицю на екран
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