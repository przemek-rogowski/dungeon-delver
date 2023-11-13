#ifndef game_hpp
#define game_hpp

#include <stdio.h>
#include "world.hpp"
#include <map>
#include "menu.hpp"
#include <memory>

enum class GameState {
    Menu,
    Game,
    Exploration,
    Combat,
    Equipment
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
    std::unique_ptr<MainMenu> GetGameMenu();
    bool isRunning = true;
    GameState gameState = GameState::Menu;
    std::unique_ptr<World> world;
    std::unique_ptr<MainMenu> mainMenu;
    std::unique_ptr<MainMenu> gameMenu;
};

#endif /* game_hpp */
