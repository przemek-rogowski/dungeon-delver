#include "menu.hpp"
#include <iostream>
#include <algorithm>
#include <cctype>

MainMenu::~MainMenu() {
    std::cout << "Destroying MainMenu object" << std::endl;
}

void MainMenu::Display() {
    std::cout << std::endl << "Available commands:" << std::endl;
    for (auto command : commands) {
        std::cout << "  " << command.name << " - " << command.description << std::endl;
    }
}

void MainMenu::AddCommand(Command command) {
    this->commands.push_back(std::move(command));
}

std::string toLowerCase(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return result;
}

void MainMenu::Process(std::string command) {
    for (auto elem : commands) {
        if (toLowerCase(elem.name) == toLowerCase(command)) {
            elem.action();
            return;
        }
    }
    std::cout << "Unknown command" << std::endl;
}
