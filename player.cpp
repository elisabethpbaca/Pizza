#include "player.h"
#include <string>
using namespace std;

Player::Player(void) {
    position.setPoint(0, 0);
    health = armor = hunger = thirst = 100;
    strength = perception = endurance = charisma = intelligence = agility = luck = 5;
    inventorySizeLimit = 10;
}

Player::Player(int strength, int perception, int endurance, int charisma, int intelligence, int agility, int luck) {
    position.setPoint(0, 0);
    health = armor = hunger = thirst = 100;
    this->strength = strength;
    this->perception = perception;
    this->endurance = endurance;
    this->charisma = charisma;
    this->intelligence = intelligence;
    this->agility = agility;
    this->luck = luck;
}

float Player::get_health(void) {
    return health;
}

float Player::get_armor(void) {
    return armor;
}

float Player::get_hunger(void) {
    return hunger;
}

float Player::get_thirst(void) {
    return thirst;
}

int Player::get_strength(void) {
    return strength;
}

int Player::get_perception(void) {
    return perception;
}

int Player::get_endurance(void) {
    return endurance;
}

int Player::get_charisma(void) {
    return charisma;
}

int Player::get_intelligence(void) {
    return intelligence;
}

int Player::get_agility(void) {
    return agility;
}

int Player::get_luck(void) {
    return luck;
}

Point Player::get_position(void) {
    return position;
}





void Player::set_health(float health) {
    this->health = health;
}

void Player::set_armor(float armor) {
    this->armor = armor;
}

void Player::set_hunger(float hunger) {
    this->hunger = hunger;
}

void Player::set_thirst(float thirst) {
    this->thirst = thirst;
}

void Player::set_strength(int strength) {
    this->strength = strength;
}

void Player::set_perception(int perception) {
    this->perception = perception;
}

void Player::set_endurance(int endurance) {
    this->endurance = endurance;
}

void Player::set_charisma(int charisma) {
    this->charisma = charisma;
}

void Player::set_intelligence(int intelligence) {
    this->intelligence = intelligence;
}

void Player::set_agility(int agility) {
    this->agility = agility;
}

void Player::set_luck(int luck) {
    this->luck = luck;
}

vector<Object*> Player::get_inventory(void) {
    return inventory;
}

void Player::show_inventory(void) {
    cout << endl << "Your Inventory" << endl;
    for(int i = 0; i < inventory.size(); i++) {
        cout << i+1 << ": " << inventory.at(i)->get_name() << endl;
    }
}

void Player::delete_from_inventory(Object* itemToDelete) {
    itemToDelete->remove_from(inventory);
}

// void Player::delete_from_inventory(Object* objPointer) {
//     *objPointer->remove_from(inventory);
// }

void Player::add_to_inventory(Object* itemToAdd) {
    if(inventory.size() < inventorySizeLimit) {
        inventory.push_back(itemToAdd);
    }else {
        cout << "There is not enough room in your inventory!" << endl;
    }
}

void Player::set_inventory(vector<Object*> inventory) {
    this->inventory = inventory;
}

bool Player::search_inventory(Child type, string itemName) {
    for(int i = 0; i < inventory.size(); i++) {
        if(inventory.at(i)->get_class() == type && inventory.at(i)->get_name() == itemName) {
            return true;
        }
    }
    return false;
}

void Player::go_north(void) {
    position.setPoint(position.getX(), position.getY() + 1);
}

void Player::go_east(void) {
    position.setPoint(position.getX() + 1, position.getY());
}

void Player::go_south(void) {
    position.setPoint(position.getX(), position.getY() - 1);
}

void Player::go_west(void) {
    position.setPoint(position.getX() - 1, position.getY());
}
