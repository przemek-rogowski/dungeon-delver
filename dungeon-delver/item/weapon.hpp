

#ifndef weapon_hpp
#define weapon_hpp

#include <iostream>
#include <string>
#include "item.h"

struct Weapon {
    Item type;
    std::string name;
    int damage;
    
    ~Weapon() {
        std::cout << "Destroying weapon: " << this->name << std::endl;
    }
};

#endif /* weapon_hpp */
