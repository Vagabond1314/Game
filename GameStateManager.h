#pragma once
#include <string>
#include <unordered_map>

class GameStateManager {
public:
    // ������ �������� ����� ���
    enum class State {
        GameStart,
        Playing,
        Menu
    };

    GameStateManager() {
        // ������������ ���������� ���� ���
        currentState = State::GameStart;

        // ���������� ���� ��� ����������� ����� � ����� � �����
        stateToStringMap[State::GameStart] = "GameStart";
        stateToStringMap[State::Playing] = "Playing";
        stateToStringMap[State::Menu] = "Menu";

        stringToStateMap["GameStart"] = State::GameStart;
        stringToStateMap["Playing"] = State::Playing;
        stringToStateMap["Menu"] = State::Menu;
    }

    // ����� ��� ��������� ��������� ����� � ������ �����
    std::string getState() const {
        return stateToStringMap.at(currentState);
    }

    // ����� ��� ������������ ����� ��� �� ��������� �����
    void setState(const std::string& state) {
        if (stringToStateMap.find(state) != stringToStateMap.end()) {
            currentState = stringToStateMap.at(state);
        }
    }

private:
    State currentState;

    // ���� ��� ����������� ����� �� enum � �������
    std::unordered_map<State, std::string> stateToStringMap;
    std::unordered_map<std::string, State> stringToStateMap;
};

