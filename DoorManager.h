#include <vector>
#include <string>
#include "Door.h"

class DoorManager {
private:
    std::vector<Door> doors; // ������ ��� ������

public:
    // ����������� ��� ���������� ������
    DoorManager(const std::vector<Door>& initialDoors) : doors(initialDoors) {}

    // ����� ��� ��������� ������ �� ������ ������
    Door* getDoorByRoomName(const std::string& roomName) {
        for (auto& door : doors) {
            if (door.getTargetRoom() == roomName) {
                return &door; // ��������� �������� �� ����
            }
        }
        return nullptr; // ���� ������ �� ��������
    }
};
