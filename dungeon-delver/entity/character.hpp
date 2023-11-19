
#ifndef character_hpp
#define character_hpp

#include <memory>
#include <string>
#include <vector>
#include "gear.hpp"
#include "character_utils.hpp"
#include "stats.h"
#include <iostream>

class Character {
public:
    Character();
    ~Character();
    
    const Stats* GetStats();
    std::string GetName();
    std::vector<std::shared_ptr<GearItem>> GetGear();
    void Display();
    void AddGear(GearItem* gear);
    
    static Character* Generate();
    
private:
    std::string name;
    std::unique_ptr<Stats> stats;
    std::vector<std::shared_ptr<GearItem>> gear;
};

#endif /* character_hpp */
