
#include "item_repository.hpp"

ItemRepository& ItemRepository::Instance() {
    static ItemRepository instance;
    return instance;
}

std::shared_ptr<Weapon> ItemRepository::CreateWeapon(Item type, std::string name, int damage) {
    auto weapon = std::make_shared<Weapon>(Weapon{type, name, damage});
    weapons[type] = weapon;
    return weapon;
}

std::shared_ptr<Armor> ItemRepository::CreateArmor(Item type, std::string name, int resistance) {
    auto armor = std::make_shared<Armor>(Armor{type, name, resistance});
    armors[type] = armor;
    return armor;
}

std::shared_ptr<Weapon> ItemRepository::GetWeapon(Item type) {
    auto it = weapons.find(type);
    return it != weapons.end() ? it->second : nullptr;
}

std::shared_ptr<Armor> ItemRepository::GetArmor(Item type) {
    auto it = armors.find(type);
    return it != armors.end() ? it->second : nullptr;
}

void ItemRepository::Init() {
    ItemRepository& itemRepo = Instance();
    itemRepo.CreateWeapon(Item::Dagger ,"Dagger", 1);
    itemRepo.CreateWeapon(Item::Sword ,"Sword", 3);
    itemRepo.CreateWeapon(Item::Axe ,"Axe", 4);
    itemRepo.CreateWeapon(Item::Mace ,"Mace", 2);
    itemRepo.CreateWeapon(Item::GreatSword ,"Great Sword", 4);
    itemRepo.CreateWeapon(Item::GreatAxe ,"Great Axe", 5);
    
    itemRepo.CreateArmor(Item::Leather, "Leather", 2);
    itemRepo.CreateArmor(Item::Chainmail, "Chainmail", 4);
    itemRepo.CreateArmor(Item::Plate, "Plate", 5);
}
