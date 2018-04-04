#include "object.h"
#include "player.h"

using namespace std;

Object::Object(void) {
    itemName = "";
    objectClass = Nothing;
}

void Object::set_name(string itemName) {
    this->itemName = itemName;
}

string Object::get_name(void) {
    return itemName;
}

Child Object::get_class(void) {
    return objectClass;
}

void Object::remove_from(vector<Object> &inventory) {
    inventory.erase(inventory.begin() + (this - &inventory.at(0)));
    delete this;
}

Weapon::Weapon(void) {
    objectClass = Child::Weapon;
    itemName = "Common Sword";
    damagePoints = 10;
    durabilityPoints = 10;
}

Weapon::Weapon(string itemName, float damagePoints, float durabilityPoints) {
    objectClass = Child::Weapon;
    this->itemName = itemName;
    this->damagePoints = damagePoints;
    this->durabilityPoints = durabilityPoints;
}

void Weapon::set_damage_points(float damagePoints) {
    this->damagePoints = damagePoints;
}

void Weapon::set_durability_points(float durabilityPoints) {
    this->durabilityPoints = durabilityPoints;
}

float Weapon::get_damage_points(void) {
    return damagePoints;
}

float Weapon::get_durability_points(void) {
    return durabilityPoints;
}

Medical::Medical(void) {
    objectClass = Child::Medical;
    itemName = "Bandages";
    revivePoints = 20;
    uses = 1;
}

Medical::Medical(string itemName, int uses, float revivePoints) {
    objectClass = Child::Medical;
    this->itemName = itemName;
    this->revivePoints = revivePoints;
    this->uses = uses;
};

void Medical::set_uses(int uses) {
    this->uses = uses;
}

void Medical::set_revive_points(float revivePoints) {
    this->revivePoints = revivePoints;
}

int Medical::get_uses(void) {
    return uses;
}

float Medical::get_revive_points(void) {
    return revivePoints;
}

void Medical::use(Player* P1) {
    P1->set_health(P1->get_health() + revivePoints);
    if(P1->get_health() > 100) {
        P1->set_health(100);
    }
    uses -= 1;
    if(uses < 0) {
        vector<Object> newInventory = P1->get_inventory();
        this->remove_from(newInventory);
        P1->set_inventory(newInventory);
    }
}

Utility::Utility(void) {
    itemName = "";
}

Utility::Utility(string itemName) {
    this->itemName = itemName;
}

Light::Light(void) {
    lightOn = 0;
}

void Light::turn_on(void) {
    lightOn = 1;
}

void Light::turn_off(void) {
    lightOn = 0;
}

bool Light::is_on(void) {
    return lightOn;
}
