
#ifndef item_repository_hpp
#define item_repository_hpp

#include <iostream>
#include <memory>
#include <unordered_map>
#include <string>
#include "weapon.hpp"
#include "armor.hpp"
#include "item.h"

class ItemRepository {
public:
    static ItemRepository& Instance();
    
    static void Init();
    
    std::shared_ptr<Weapon> CreateWeapon(Item type, std::string name, int damage);
    std::shared_ptr<Armor> CreateArmor(Item type, std::string name, int resistance);
    
    std::shared_ptr<Weapon> GetWeapon(Item type);
    std::shared_ptr<Armor> GetArmor(Item type);
    
private:
    ItemRepository() {}
    
    std::unordered_map<Item, std::shared_ptr<Weapon>> weapons;
    std::unordered_map<Item, std::shared_ptr<Armor>> armors;
};

#endif /* item_repository_hpp */
