
#include "character.hpp"
#include <iostream>
#include "../item/item_repository.hpp"

Character::Character() {}

Character::~Character() {
    std::cout << "Destroying character: " << this->name << std::endl;
}

Stats* Character::GetStats() {
    return this->stats.get();
}

std::string Character::GetName() {
    return this->name;
}

std::shared_ptr<Weapon> Character::GetWeapon() {
    return this->weapon;
}

std::shared_ptr<Armor> Character::GetArmor() {
    return this->armor;
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
    character->weapon = ItemRepository::Instance().GetWeapon(Item::Sword);
    character->armor = ItemRepository::Instance().GetArmor(Item::Leather);
    return character;
}
