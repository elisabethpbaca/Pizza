#include "map.h"
using namespace std;

Map::Map(void) {
    class Utility* rope = new class Utility;
    Weapon* gun = new Weapon;
    gun->set_name("AR-15");
    gun->set_damage_points(50);
    rope->set_name("rope");
    objectGrid[0][1].push_back(rope);
    objectGrid[2][2].push_back(gun);

    Wall* w1 = new Wall;

    structureGrid[1][1].push_back(w1);
    structureGrid[2][2].push_back(w1);
    structureGrid[3][1].push_back(w1);

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
