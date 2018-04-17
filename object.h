#ifndef _OBJECT
#define _OBJECT

#include <string>
#include <vector>
#include "player.h"
#include "child.h"

using namespace std;


class Player;

class Object {
    protected:
        string itemName;
        Child objectClass;
    public:
        // Constructors
        Object(void);

        // Setters
        void set_name(string itemName);

        //Getters
        string get_name(void);
        Child get_class(void);

        // Mutators
        void remove_from(vector<Object*> &inventory);
};

class Weapon : public Object {
    private:
        float damagePoints, durabilityPoints;

    public:
        // Constructors
        Weapon(void);
        Weapon(string itemName, float damagePoints, float durabilityPoints);

        // Setters
        void set_damage_points(float damagePoints);
        void set_durability_points(float durabilityPoints);

        // Getters
        float get_damage_points(void);
        float get_durability_points(void);
};

class Medical : public Object {
    private:
        int uses;
        float revivePoints;
    public:
        // Constructors
        Medical(void);
        Medical(string itemName, int uses, float revivePoints);

        // Setters
        void set_uses(int uses);
        void set_revive_points(float revivePoints);

        // Getters
        int get_uses(void);
        float get_revive_points(void);

        // Mutators
        void use(Player* P1);


};

class Utility : public Object {
    private:

    public:
        // Constructors
        Utility(void);
        Utility(string itemName);
};

class Light : public Object {
    private:
        bool lightOn;
    public:
        // Constructors
        Light(void);

        // Setters
        void turn_on(void);
        void turn_off(void);

        // Getters
        bool is_on(void);
};

#endif
