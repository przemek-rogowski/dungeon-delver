#include <iostream>
#include "game.hpp"

int main(int argc, const char * argv[]) {
    std::cout << "Hello, Dungeon Delver!" << std::endl;
    
    Game game;
    game.Init();
    game.Start();
    game.Clean();
    
    return 0;
}
