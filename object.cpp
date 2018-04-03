#include "object.h"

using namespace std;

Object::Object(void) {
    objectType = Nothing;
    itemName = "";
    uses = 0;
    damagePoints = revivePoints = hungerPoints = thirstPoints = 0;
    lightOn = 0;
}

void Object::set_object(Item objectType, string itemName, int uses, float itemPoints) {
    this->objectType = objectType;
    this->itemName = itemName;
    this->uses = uses;
    if(objectType == Medkit) {
        this->revivePoints = itemPoints;
        damagePoints = hungerPoints = thirstPoints = 0;
    }else if(objectType == Weapon) {
        this->damagePoints = itemPoints;
        revivePoints = hungerPoints = thirstPoints = 0;
    }else if(objectType == Food) {
        this->hungerPoints = itemPoints;
        damagePoints = revivePoints = thirstPoints = 0;
    }else if(objectType == Water) {
        this->thirstPoints = itemPoints;
        damagePoints = hungerPoints = revivePoints = 0;
    }
    lightOn = 0;
}

void Object::set_object(/* Light */ string itemName) {
    objectType = Light;
    this->itemName = itemName;
    uses = 100;
    damagePoints = revivePoints = hungerPoints = thirstPoints = 0;
    lightOn = 0;
}

Item Object::get_item_type(void) {
    return objectType;
}

string Object::get_item(void) {
    return itemName;
}

int Object::get_uses(void) {
    return uses;
}

float Object::get_damage_points(void) {
    return damagePoints;
}

float Object::get_revive_points(void) {
    return revivePoints;
}

float Object::get_hunger_points(void) {
    return hungerPoints;
}

float Object::get_thirst_points(void) {
    return thirstPoints;
}

bool Object::is_light_on(void) {
    return lightOn;
}
