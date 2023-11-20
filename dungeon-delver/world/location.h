
#ifndef location_h
#define location_h

#include <iostream>

struct Terrain {
    std::string name;
    char shortName;
};

struct Position {
    int x;
    int y;
};

struct Location {
    std::string name;
    Terrain terrain;
    bool isExplored;
    
    Location(std::string name, Terrain terrain): name(name), terrain(terrain), isExplored(false){}
    ~Location() {
        std::cout << "Destroying location: " << this->name << std::endl;
    }
};

#endif /* location_h */
