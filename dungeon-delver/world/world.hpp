#ifndef world_hpp
#define world_hpp

#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <memory>
#include "location.h"

enum class Travel {
    North,
    East,
    South,
    West
};

class World {
public:
    World() = default;
    ~World();
    void Load(const std::string mapFileName);
    std::shared_ptr<Location> GetCurrentLoc();
    
    void Move(Travel travel);
    void Display();
private:
    std::vector<std::vector<std::shared_ptr<Location>>> locations;
    Position curLocation;
};

#endif /* world_hpp */
