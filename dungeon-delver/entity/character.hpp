
#ifndef character_hpp
#define character_hpp

#include <memory>
#include <string>
#include <vector>
#include "gear.hpp"
#include "character_utils.hpp"

struct Stats {
    int strength;
    int agility;
    int wits;
    int charisma;
    
    std::string ToString() {
        return "Strength: " + std::to_string(strength) + "\n"
                       "Agility: " + std::to_string(agility) + "\n"
                       "Wits: " + std::to_string(wits) + "\n"
                       "Charisma: " + std::to_string(charisma);
    }
};

class Character {
public:
    Character() {
        this->name = CharacterUtils::GenerateName();
        this->stats = Stats {12, 13, 11, 10};
    };
    ~Character();
    
    Stats GetStats();
    std::string GetName();
    std::vector<std::shared_ptr<GearItem>> GetGear();
    void AddGear(GearItem* gear);
private:
    std::string name;
    Stats stats;
    std::vector<std::shared_ptr<GearItem>> gear;
};

#endif /* character_hpp */
