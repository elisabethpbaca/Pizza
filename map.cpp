#include "map.h"
using namespace std;

Map::Map(void) {
    Utility* u1 = new Utility;
    u1->set_name("map");
    Weapon* a1 = new Weapon;
    a1->set_name("Common Sword");
    a1->set_damage_points(25);
    a1->set_durability_points(10);
    Medical* m1 = new Medical;
    m1->set_name("Potion of Healing");
    m1->set_revive_points(50);
    m1->set_uses(1);
    Wall* w1 = new Wall;
    Foliage* f1 = new Foliage;
    objectGrid[3][5].push_back(u1);
    objectGrid[3][2].push_back(m1);
    objectGrid[1][4].push_back(a1);

    structureGrid[4][6].push_back(f1);

    structureGrid[0][4].push_back(w1);
    structureGrid[1][3].push_back(w1);
    structureGrid[1][5].push_back(w1);
    structureGrid[1][9].push_back(w1);
    structureGrid[1][10].push_back(w1);
    structureGrid[1][11].push_back(w1);
    structureGrid[1][12].push_back(w1);
    structureGrid[2][2].push_back(w1);
    structureGrid[2][6].push_back(w1);
    structureGrid[2][8].push_back(w1);
    structureGrid[2][13].push_back(w1);
    structureGrid[3][1].push_back(w1);
    structureGrid[3][6].push_back(w1);
    structureGrid[3][7].push_back(w1);
    structureGrid[3][8].push_back(w1);
    structureGrid[3][13].push_back(w1);
    structureGrid[3][14].push_back(w1);
    structureGrid[3][15].push_back(w1);
    structureGrid[4][2].push_back(w1);
    structureGrid[5][3].push_back(w1);
    structureGrid[5][4].push_back(w1);
    structureGrid[5][6].push_back(w1);
    structureGrid[5][7].push_back(w1);
    structureGrid[5][8].push_back(w1);
    structureGrid[6][4].push_back(w1);
    structureGrid[6][6].push_back(w1);

}

vector<Object*> Map::get_objects(int x, int y) {
    return objectGrid[x][y];
}

vector<Structure*> Map::get_structures(int x, int y) {
    return structureGrid[x][y];
}

void Map::delete_object(int x, int y, string itemName) {
    for(int i = 0; i < objectGrid[x][y].size(); i++) {
        if(objectGrid[x][y].at(i)->get_name() == itemName) {
            objectGrid[x][y].erase(objectGrid[x][y].begin() + i);
        }
    }
}
