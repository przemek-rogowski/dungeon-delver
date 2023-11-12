#ifndef game_hpp
#define game_hpp

#include <stdio.h>
#include "world.hpp"
#include <map>

class Game {
public:
    Game() = default;
    ~Game();
    void Init();
    void Start();
    void Clean();
    
private:
    void DisplayInfo();
    void DisplayHelp();
    
    World* world;
    std::map<std::string, std::function<bool()>> commandMap;
    
};

#endif /* game_hpp */
