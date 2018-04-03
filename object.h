#ifndef _OBJECT
#define _OBJECT

#include <string>

using namespace std;

enum Item { Medkit, Weapon, Light, Food, Water, Nothing };

class Object {
    private:
        Item objectType;
        string itemName;
        int uses;
        float damagePoints, revivePoints, hungerPoints, thirstPoints;
        bool lightOn;
    public:
        // Constructors
        Object(void);

        // Setters
        void set_object(Item objectType, string itemName, int uses, float itemPoints);
        void set_object(/* Light */ string itemName);

        // Getters
        Item get_item_type(void);
        string get_item(void);
        int get_uses(void);
        float get_damage_points(void);
        float get_revive_points(void);
        float get_hunger_points(void);
        float get_thirst_points(void);
        bool is_light_on(void);

};

#endif
