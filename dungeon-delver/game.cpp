#include "game.hpp"
#include <string>
#include <iostream>

Game::~Game() {
}

void Game::Init() {
    this->world = new World();
    this->world->Load("kingdom");
    
    commandMap["quit"] = [this]() {
        std::cout << "Goodbye! Thanks for playing." << std::endl;
        return true;
    };
    commandMap["help"] = [this]() {
        this->DisplayHelp();
        return false;
    };
    commandMap["map"] = [this]() {
        this->world->display();
        return false;
    };
    commandMap["move N"] = [this]() {
        std::cout << "Moving north." << std::endl;
        return false;
    };
    commandMap["move E"] = [this]() {
        std::cout << "Moving east." << std::endl;
        return false;
    };
    commandMap["move S"] = [this]() {
        std::cout << "Moving south." << std::endl;
        return false;
    };
    commandMap["move W"] = [this]() {
        std::cout << "Moving west." << std::endl;
        return false;
    };
}

void Game::Clean() {
    delete world;
    world = nullptr;
}

void Game::Start() {
    
    DisplayInfo();
    DisplayHelp();

    while (true) {
        std::cout << "\nEnter a command: ";
        std::string command;
        std::getline(std::cin, command);

        auto it = commandMap.find(command);
        if (it != commandMap.end()) {
            if (it->second()) {
                // end of the game
                break;
            }
        } else {
            std::cout << "Unknown command" << std::endl;
        }
    }
}

void Game::DisplayInfo() {
    std::cout << "Welcome to the Dungeon Dwelver!" << std::endl;
}

void Game::DisplayHelp() {
    std::cout << "\nAvailable commands:" << std::endl;
    std::cout << "  help - Display this help message" << std::endl;
    std::cout << "  map - Show map" << std::endl;
    std::cout << "  look - Look around to observe your surroundings" << std::endl;
    std::cout << "  move [N,E,S,W] - Move to another location" << std::endl;
    std::cout << "  quit/exit - Save and quit the game" << std::endl;
}
