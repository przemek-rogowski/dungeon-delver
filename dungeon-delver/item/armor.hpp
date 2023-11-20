
#ifndef armor_hpp
#define armor_hpp

#include <string>
#include "item.h"

struct Armor {
    Item type;
    std::string name;
    int resistance;
    
    ~Armor() {
        std::cout << "Destroying armor: " << this->name << std::endl;
    }
};

#endif /* armor_hpp */
