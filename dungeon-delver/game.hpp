#ifndef game_hpp
#define game_hpp

#include <stdio.h>
#include "world/world.hpp"
#include <map>
#include "menu.hpp"
#include <memory>
#include "entity/character.hpp"

enum class GameState {
    Menu,
    Game,
    Exploration,
    Combat,
    Equipment,
    Travel
    /*
     when you open the game -> Menu
     when you load or start a game -> Game
     when you explore a location -> Exploration
     when you enter in a combat -> Combat
     when you look at the equipment -> Equipment
     */
};

class Game {
public:
    Game() = default;
    ~Game();
    void Init();
    void Start();
    void Clean();
    
private:
    void DisplayInfo();
    MainMenu* InitMainMenu();
    MainMenu* InitGameMenu();
    MainMenu* InitExplorationMenu();
    MainMenu* InitCombatMenu();
    MainMenu* InitTravelMenu();
    
    std::unique_ptr<MainMenu> mainMenu;
    std::unique_ptr<MainMenu> gameMenu;
    std::unique_ptr<MainMenu> explorationMenu;
    std::unique_ptr<MainMenu> combatMenu;
    std::unique_ptr<MainMenu> travelMenu;
    
    bool isRunning = true;
    
    GameState gameState = GameState::Menu;
    
    std::unique_ptr<World> world;
    std::unique_ptr<Character> character;
};

#endif /* game_hpp */
