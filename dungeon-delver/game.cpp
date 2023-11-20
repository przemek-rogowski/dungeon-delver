#include "game.hpp"
#include <string>
#include <iostream>
#include <limits>
#include "item/item_repository.hpp"

std::string readCommand() {
    std::cout << "\nEnter a command: ";
    std::string command;
    std::getline(std::cin, command);
    std::cout << std::endl;
    return command;
}

MainMenu* Game::InitGameMenu() {
    MainMenu* menu = new MainMenu();
    menu->AddCommand(Command{
        "character",
        "See character details.",
        [this]() {
            this->character->Display();
        }
    });
    menu->AddCommand(Command{
        "gear",
        "See character gear.",
        [this]() {
            std::cout << "Your equipment:" << std::endl;
            auto weapon = character->GetWeapon();
            if (weapon) {
                std::cout << "  " << weapon->name << " - damage +" << weapon->damage << std::endl;
            } else {
                std::cout << "  no weapon" << std::endl;
            }
            
            auto armor = character->GetArmor();
            if (armor) {
                std::cout << "  " << armor->name << " - resistance +" << armor->resistance << std::endl;
            } else {
                std::cout << "  no armor" << std::endl;
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
        [this]() {
            std::cout << "Traveling..." << std::endl;
            this->gameState = GameState::Travel;
        }
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

MainMenu* Game::InitMainMenu() {
    MainMenu* menu = new MainMenu();
    menu->AddCommand(Command{
        "new game",
        "Start a new game.",
        [this]() {
            std::cout << "Starting a new game." << std::endl;
            this->gameState = GameState::Game;
            this->character = std::unique_ptr<Character>(Character::Generate());
            this->gameMenu = std::unique_ptr<MainMenu>(InitGameMenu());
        }
    });
    menu->AddCommand(Command{
        "load game",
        "Continue your previous game.",
        [this]() { std::cout << "Loading a game" << std::endl;}
    });
    menu->AddCommand(Command{
        "help",
        "Display this help message.",
        [this]() { this->mainMenu->Display(); }
    });
    menu->AddCommand(Command{
        "exit",
        "Moving to another location.",
        [this]() {
            std::cout << "Goodbye! Thanks for playing." << std::endl;
            this->isRunning = false;
        }
    });
    return menu;
}

MainMenu* Game::InitExplorationMenu() {
    MainMenu* menu = new MainMenu();
    // TODO display description
    menu->AddCommand(Command{
        "enter",
        "Enter the location.",
        [this]() { std::cout << "It's dark..." << std::endl;}
    });
    menu->AddCommand(Command{
        "fight",
        "Fight the monster.",
        [this]() {
            std::cout << "It's time for a fight." << std::endl;
            //this->combatMenu = std::unique_ptr<MainMenu>(InitCombatMenu());
        }
    });
    menu->AddCommand(Command{
        "leave",
        "Leave the location.",
        [this]() { std::cout << "Leaving the location." << std::endl;}
    });
    return menu;
}

MainMenu* Game::InitCombatMenu() {
    MainMenu* menu = new MainMenu();
    menu->AddCommand(Command{
        "attack",
        "Perform offensive attack.",
        [this]() { std::cout << "You have hit." << std::endl;}
    });
    menu->AddCommand(Command{
        "defend",
        "Perform defensive attack.",
        [this]() { std::cout << "You have hit." << std::endl;}
    });
    menu->AddCommand(Command{
        "run",
        "Run away from the fight.",
        [this]() { std::cout << "You have run away." << std::endl;}
    });
    return menu;
}

MainMenu* Game::InitTravelMenu() {
    MainMenu* menu = new MainMenu();
    
    menu->AddCommand(Command{
        "north",
        "Go north - Desert",
        [this]() {
            std::cout << "You are going north" << std::endl;
            this->world->Move(Travel::North);
            this->gameState = GameState::Game;
        }
    });
    menu->AddCommand(Command{
        "east",
        "Go east - Forest",
        [this]() {
            std::cout << "You are going east" << std::endl;
            this->world->Move(Travel::East);
            this->gameState = GameState::Game;
        }
    });
    menu->AddCommand(Command{
        "south",
        "Go south - Plains",
        [this]() {
            std::cout << "You are going south" << std::endl;
            this->world->Move(Travel::South);
            this->gameState = GameState::Game;
        }
    });
    menu->AddCommand(Command{
        "west",
        "Go north - City",
        [this]() {
            std::cout << "You are going west" << std::endl;
            this->world->Move(Travel::West);
            this->gameState = GameState::Game;
        }
    });
    menu->AddCommand(Command{
        "back",
        "Cancel the journey.",
        [this]() {
            std::cout << "You have canceled the journey." << std::endl;
            this->gameState = GameState::Game;
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
    ItemRepository::Init();
    
    this->world = std::make_unique<World>();
    this->mainMenu = std::unique_ptr<MainMenu>(InitMainMenu());
    this->explorationMenu = std::unique_ptr<MainMenu>(InitExplorationMenu());
    this->combatMenu = std::unique_ptr<MainMenu>(InitCombatMenu());
    this->travelMenu = std::unique_ptr<MainMenu>(InitTravelMenu());
    
    this->world->Load("../assets.world_map.txt");
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
            case GameState::Travel:
                this->travelMenu->Display();
                this->travelMenu->Process(readCommand());
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

