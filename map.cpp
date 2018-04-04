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
}

vector<Object*> Map::get_objects(int x, int y) {
    return objectGrid[x][y];
}

void Map::delete_object(int x, int y, string itemName) {
    for(int i = 0; i < objectGrid[x][y].size(); i++) {
        if(objectGrid[x][y].at(i)->get_name() == itemName) {
            objectGrid[x][y].erase(objectGrid[x][y].begin() + i);
        }
    }
}
