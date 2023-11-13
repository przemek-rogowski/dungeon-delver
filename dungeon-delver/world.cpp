#include "world.hpp"
#include <iostream>
#include <vector>

using std::vector;

Terrain plain{"plain", 'P'};
Terrain forest{"forest", 'F'};
Terrain mountain{"mountain", 'M'};
Terrain city{"city", 'C'};

char playerChar = 'x';

World::~World() {
    std::cout << "Destroying world object" << std::endl;
}

void World::Load(string name) {
    this->locationName = name;
    this->locations = vector<vector<Location>>{
        {
            Location{"plain1", plain, false},
            Location{"plain2", plain, false},
            Location{"plain3", plain, false},
            Location{"plain4", plain, false},
            Location{"plain5", plain, false},
            Location{"plain6", plain, false}
        },
        {
            Location{"plain7", plain, false},
            Location{"forest1", forest, false},
            Location{"forest2", forest, false},
            Location{"forest3", forest, false},
            Location{"forest4", forest, false},
            Location{"plain8", plain, false}
        },
        {
            Location{"plain9", plain, false},
            Location{"forest5", forest, false},
            Location{"city1", city, false},
            Location{"city2", city, false},
            Location{"forest6", forest, false},
            Location{"plain10", plain, false}
        },
        {
            Location{"plain11", plain, false},
            Location{"mountain1", mountain, false},
            Location{"mountain2", mountain, false},
            Location{"mountain3", mountain, false},
            Location{"mountain4", mountain, false},
            Location{"plain12", plain, false}
        }
    };
    
    curLocation = {2, 2};
}

void World::Display() {
    std::cout << std::endl << "Location: " << this->locationName << std::endl << std::endl;
    for (int i = 0; i < locations.size(); i++) {
        for (int j = 0; j < locations[i].size(); j++) {
            if (curLocation.x == i && curLocation.y == j) {
                std::cout << playerChar << " ";
            } else {
                std::cout << locations[i][j].terrain.shortName << " ";
            }
        }
        std::cout << std::endl;
    }
}
