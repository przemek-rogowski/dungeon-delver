
#include "character.hpp"
#include <iostream>

Character::Character() {}

Character::~Character() {
    std::cout << "Destroying character: " << this->name << std::endl;
}

const Stats* Character::GetStats() {
    return this->stats.get();
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

void Character::Display() {
    std::cout << "Character sheet" << std::endl;
    std::cout << "****************" << std::endl;
    std::cout << "Name: " << this->GetName() << std::endl;
    std::cout << this->stats->ToString() << std::endl;
    std::cout << "****************" << std::endl;
}

Character* Character::Generate() {
    Character* character = new Character();
    std::cout << "Generating a character" << std::endl;
    character->name = CharacterUtils::GenerateName();
    character->stats = std::unique_ptr<Stats>(CharacterUtils::GenerateStats());
    return character;
}
