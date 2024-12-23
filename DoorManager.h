#include <vector>
#include <string>
#include "Door.h"

class DoorManager {
private:
    std::vector<Door> doors; // Вектор усіх дверей

public:
    // Конструктор для заповнення дверей
    DoorManager(const std::vector<Door>& initialDoors) : doors(initialDoors) {}

    // Метод для отримання дверей за назвою кімнати
    Door* getDoorByRoomName(const std::string& roomName) {
        for (auto& door : doors) {
            if (door.getTargetRoom() == roomName) {
                return &door; // Повертаємо вказівник на двері
            }
        }
        return nullptr; // Якщо дверей не знайдено
    }
};
