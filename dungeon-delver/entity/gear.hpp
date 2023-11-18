

#ifndef gear_hpp
#define gear_hpp

#include <string>
#include <iostream>

struct GearItem {
    ~GearItem() {
        std::cout << "Destroying gear item: " << this->name << std::endl;
    }
    
    std::string name;
};

#endif /* gear_hpp */
