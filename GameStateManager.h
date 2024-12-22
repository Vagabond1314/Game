#pragma once
#include <string>
#include <unordered_map>

class GameStateManager {
public:
    // Перелік можливих станів гри
    enum class State {
        GameStart,
        Playing,
        Menu
    };

    GameStateManager() {
        // Встановлюємо початковий стан гри
        currentState = State::GameStart;

        // Ініціалізуємо мапу для конвертації станів в рядки і назад
        stateToStringMap[State::GameStart] = "GameStart";
        stateToStringMap[State::Playing] = "Playing";
        stateToStringMap[State::Menu] = "Menu";

        stringToStateMap["GameStart"] = State::GameStart;
        stringToStateMap["Playing"] = State::Playing;
        stringToStateMap["Menu"] = State::Menu;
    }

    // Метод для отримання поточного стану у вигляді рядка
    std::string getState() const {
        return stateToStringMap.at(currentState);
    }

    // Метод для встановлення стану гри за допомогою рядка
    void setState(const std::string& state) {
        if (stringToStateMap.find(state) != stringToStateMap.end()) {
            currentState = stringToStateMap.at(state);
        }
    }

private:
    State currentState;

    // Мапи для конвертації станів між enum і рядками
    std::unordered_map<State, std::string> stateToStringMap;
    std::unordered_map<std::string, State> stringToStateMap;
};

