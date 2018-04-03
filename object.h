#ifndef _OBJECT
#define _OBJECT



using namespace std;

enum Type { Medkit, Weapon, Light, Food, Water };

class Object {
    private:
        Type objectType;
        int uses;
        float damagePoints, revivePoints, hungerPoints, thirstPoints;
        bool lightOn;
    public:
        Object(void);

};

#endif
