#include "game.hpp"
#include <string>
#include <iostream>
#include <limits>
//#include "entity/character.hpp"

std::string readCommand() {
    std::cout << "\nEnter a command: ";
    std::string command;
    std::getline(std::cin, command);
    std::cout << std::endl;
    return command;
}

std::unique_ptr<MainMenu> Game::GetGameMenu() {
    std::unique_ptr<MainMenu> menu = std::make_unique<MainMenu>();
    menu->AddCommand(Command{
        "character",
        "See character details.",
        [this]() {
            std::cout << "Character sheet" << std::endl;
            std::cout << "****************" << std::endl;
            std::cout << "Name: " << this->character->GetName() << std::endl;
            std::cout << this->character->GetStats().ToString() << std::endl;
            std::cout << "****************" << std::endl;
        }
    });
    menu->AddCommand(Command{
        "gear",
        "See character gear.",
        [this]() {
            std::cout << "Your equipment:" << std::endl;
            for (auto item : this->character->GetGear()) {
                std::cout << "  " << item->name << std::endl;
            }
        }
    });
    menu->AddCommand(Command{
        "map",
        "Display map of the kingdom.",
        [this]() {
            this->world->Display();
        }
    });
    menu->AddCommand(Command{
        "explore",
        "Eplore the current location.",
        [this]() { std::cout << "Exploring..." << std::endl;}
    });
    menu->AddCommand(Command{
        "travel",
        "Travel to a new location.",
        [this]() { std::cout << "Traveling..." << std::endl;}
    });
    menu->AddCommand(Command{
        "leave",
        "Save & quit the game.",
        [this]() {
            std::cout << "Saving the game..." << std::endl;
            this->gameState = GameState::Menu;
            this->gameMenu = nullptr;
            this->character = nullptr;
        }
    });
    return menu;
}

Game::~Game() {
    std::cout << "Destroying game object" << std::endl;
}

void Game::DisplayInfo() {

    std::cout << "    ___    __ __  ____    ____    ___   ___   ____       ___    __    __    ___  _      __ __    ___  ____ \n";
    std::cout << "   |   \\  |  |  ||    \\  /    |  /  _] /   \\ |    \\     |   \\  |  |__|  |  /  _]| |    |  |  |  /  _]|    \\ \n";
    std::cout << "   |    \\ |  |  ||  _  ||   __| /  [_ |     ||  _  |    |    \\ |  |  |  | /  [_ | |    |  |  | /  [_ |  D  ) \n";
    std::cout << "   |  D  ||  |  ||  |  ||  |  ||    _]|  O  ||  |  |    |  D  ||  |  |  ||    _]| |___ |  |  ||    _]|    / \n";
    std::cout << "   |     ||  :  ||  |  ||  |_ ||   [_ |     ||  |  |    |     ||  `  '  ||   [_ |     ||  :  ||   [_ |    \\ \n";
    std::cout << "   |     ||     ||  |  ||     ||     ||     ||  |  |    |     | \\      / |     ||     | \\   / |     ||  .  \\ \n";
    std::cout << "   |_____| \\__,_||__|__||___,_||_____| \\___/ |__|__|    |_____|  \\_/\\_/  |_____||_____|  \\_/  |_____||__|\\_| \n";

    std::cout << std::endl << "Welcome to the Dungeon Dwelver!" << std::endl;
}

void Game::Init() {
    this->world = std::make_unique<World>();
    this->mainMenu = std::make_unique<MainMenu>();
    
    /*
     Game ->
        character
        gear
        explore
        map
        travel
        exit [save & quit]
     
     Exploration
        - list of the places to visit
        - go back
     
     Combat
        - attack
        - defend
        - run away
     
     */
    
    this->world->Load("Kingdom of Velanor");
    
    this->mainMenu->AddCommand(Command{
        "new game",
        "Start a new game.",
        [this]() {
            std::cout << "Starting a new game." << std::endl;
            this->gameState = GameState::Game;
            this->gameMenu = GetGameMenu();
            this->character = std::make_shared<Character>();
            this->character->AddGear(new GearItem{"Sword"});
            this->character->AddGear(new GearItem{"Dagger"});
        }
    });
    this->mainMenu->AddCommand(Command{
        "load game",
        "Continue your previous game.",
        [this]() { std::cout << "Loading a game" << std::endl;}
    });
    this->mainMenu->AddCommand(Command{
        "help",
        "Display this help message.",
        [this]() { this->mainMenu->Display(); }
    });
    this->mainMenu->AddCommand(Command{
        "exit",
        "Moving to another location.",
        [this]() {
            std::cout << "Goodbye! Thanks for playing." << std::endl;
            this->isRunning = false;
        }
    });

}

void Game::Clean() {
}

void Game::Start() {
    
    while (this->isRunning) {
        system("clear");
        this->DisplayInfo();
        switch (this->gameState) {
            case GameState::Menu:
                this->mainMenu->Display();
                this->mainMenu->Process(readCommand());
                break;
            case GameState::Game:
                this->gameMenu->Display();
                this->gameMenu->Process(readCommand());
                break;
            case GameState::Exploration:
                break;
            case GameState::Combat:
                break;
                
            default:
                std::cout << "Unknown game state" << std::endl;
                this->isRunning = false;
                break;
        }
    
        std::cout << std::endl << "Press Enter to continue...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

