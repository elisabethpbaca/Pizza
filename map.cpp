#include "map.h"
using namespace std;

Map::Map(void) {
    objectGrid[0][1].set_object(Weapon, "rope", 100, 100);
}

Object Map::get_object(int x, int y) {
    return objectGrid[x][y];
}
