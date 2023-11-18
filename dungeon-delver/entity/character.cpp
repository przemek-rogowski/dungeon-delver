
#include "character.hpp"
#include <iostream>

Character::~Character() {
    std::cout << "Destroying character: " << this->name << std::endl;
}

Stats Character::GetStats() {
    return this->stats;
}

std::string Character::GetName() {
    return this->name;
}

std::vector<std::shared_ptr<GearItem>> Character::GetGear() {
    return this->gear;
}

void Character::AddGear(GearItem* gearItem) {
    this->gear.push_back(std::make_shared<GearItem>(*gearItem));
}
