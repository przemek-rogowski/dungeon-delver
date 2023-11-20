#include "world.hpp"
#include <iostream>
#include <vector>

using std::vector;

Terrain plain{"plain", 'P'};
Terrain forest{"forest", 'F'};
Terrain mountain{"mountain", 'M'};
Terrain city{"city", 'C'};

char playerChar = '.';

World::~World() {
    std::cout << "Destroying world object" << std::endl;
}

void World::Load(const std::string mapFileName) {

    std::shared_ptr<Location> city1 = std::shared_ptr<Location>(new Location{"City", Terrain{"City", 'C'}});
    std::shared_ptr<Location> forest1 = std::shared_ptr<Location>(new Location{"Forest", Terrain{"Forest", 'F'}});
    std::shared_ptr<Location> plains1 = std::shared_ptr<Location>(new Location{"Plains", Terrain{"Plains", 'P'}});
    std::shared_ptr<Location> mountains1 = std::shared_ptr<Location>(new Location{"Mountains", Terrain{"Mountains", 'M'}});
    locations.push_back({city1, forest1, plains1, mountains1});
    
    std::shared_ptr<Location> city2 = std::shared_ptr<Location>(new Location{"City", Terrain{"City", 'C'}});
    std::shared_ptr<Location> forest2 = std::shared_ptr<Location>(new Location{"Forest", Terrain{"Forest", 'F'}});
    std::shared_ptr<Location> plains2 = std::shared_ptr<Location>(new Location{"Plains", Terrain{"Plains", 'P'}});
    std::shared_ptr<Location> mountains2 = std::shared_ptr<Location>(new Location{"Mountains", Terrain{"Mountains", 'M'}});
    locations.push_back({city2, forest2, plains2, mountains2});
    
    std::shared_ptr<Location> city3 = std::shared_ptr<Location>(new Location{"City", Terrain{"City", 'C'}});
    std::shared_ptr<Location> forest3 = std::shared_ptr<Location>(new Location{"Forest", Terrain{"Forest", 'F'}});
    std::shared_ptr<Location> plains3 = std::shared_ptr<Location>(new Location{"Plains", Terrain{"Plains", 'P'}});
    std::shared_ptr<Location> mountains3 = std::shared_ptr<Location>(new Location{"Mountains", Terrain{"Mountains", 'M'}});
    locations.push_back({city3, forest3, plains3, mountains3});
    
    std::shared_ptr<Location> city4 = std::shared_ptr<Location>(new Location{"City", Terrain{"City", 'C'}});
    std::shared_ptr<Location> forest4 = std::shared_ptr<Location>(new Location{"Forest", Terrain{"Forest", 'F'}});
    std::shared_ptr<Location> plains4 = std::shared_ptr<Location>(new Location{"Plains", Terrain{"Plains", 'P'}});
    std::shared_ptr<Location> mountains4 = std::shared_ptr<Location>(new Location{"Mountains", Terrain{"Mountains", 'M'}});
    locations.push_back({city4, forest4, plains4, mountains4});
    
    curLocation = {0, 0};
}

std::shared_ptr<Location> World::GetCurrentLoc() {
    return this->locations[curLocation.x][curLocation.y];
}

void World::Move(Travel travel) {
    Position& pos = this->curLocation;
    switch (travel) {
        case Travel::North:
            if (pos.x > 0) {
                pos = {pos.x-1, pos.y};
            }
            break;
        case Travel::East:
            if (pos.y < locations[0].size()-1) {
                pos = {pos.x, pos.y+1};
            }
            break;
        case Travel::South:
            if (pos.x < locations.size()-1) {
                pos = {pos.x+1, pos.y};
            }
            break;
        case Travel::West:
            if (pos.y > 0) {
                pos = {pos.x, pos.y-1};
            }
            break;
            
        default:
            break;
    }
}

void World::Display() {
    std::cout << std::endl << "Map of Kingdom of Velanor" << std::endl << std::endl;
    for (int i = 0; i < locations.size(); i++) {
        for (int j = 0; j < locations[i].size(); j++) {
            if (curLocation.x == i && curLocation.y == j) {
                std::cout << playerChar << " ";
            } else {
                std::cout << locations[i][j]->terrain.shortName << " ";
            }
        }
        std::cout << std::endl;
    }
}
