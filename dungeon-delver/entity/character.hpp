
#ifndef character_hpp
#define character_hpp

#include <memory>
#include <string>
#include <vector>
#include "character_utils.hpp"
#include "stats.h"
#include <iostream>

#include "../item/weapon.hpp"
#include "../item/armor.hpp"

class Character {
public:
    Character();
    ~Character();
    
    Stats* GetStats();
    std::string GetName();
    std::shared_ptr<Weapon> GetWeapon();
    std::shared_ptr<Armor> GetArmor();
    
    void Display();
    
    static Character* Generate();
    
private:
    std::string name;
    std::unique_ptr<Stats> stats;
    std::shared_ptr<Weapon> weapon;
    std::shared_ptr<Armor> armor;
    
};

#endif /* character_hpp */
