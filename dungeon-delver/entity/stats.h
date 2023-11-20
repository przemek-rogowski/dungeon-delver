
#ifndef stats_h
#define stats_h

#include <iostream>

struct Stats {
    int strength;
    int agility;
    int wits;
    int charisma;
    
    ~Stats() {
        std::cout << "Destroying Stats" << std::endl;
    }
    
    std::string ToString() const {
        return "Strength: " + std::to_string(strength) + "\n"
                       "Agility: " + std::to_string(agility) + "\n"
                       "Wits: " + std::to_string(wits) + "\n"
                       "Charisma: " + std::to_string(charisma);
    }
};

#endif /* stats_h */
