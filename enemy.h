#ifndef _ENEMY
#define _ENEMY

#include <string>
#include "helpers.h"
#include "player.h"
#include "child.h"
#include "map.h"

using namespace std;

class Player;

class Enemy {
    protected:
        float health, damagePoints;
        bool hostile;
        EnemyType thisEnemy;
    public:
        // Constructors
        Enemy(void);
        Enemy(EnemyType thisEnemy);

        // Setters
        void set_health(float health);
        void set_damage_points(float damagePoints);
        void set_hostile(bool hostile);

        // Getters
        EnemyType get_type(void);
        float get_health(void);
        float get_damage_points(void);
        bool is_hostile(void);

        void attack(Player* dumbAss);

};

#endif
