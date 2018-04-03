#include "map.h"
using namespace std;

Map::Map(void) {
    objectGrid[10][9].set_object(Weapon, "rope", 100, 100);
}

Object Map::get_object(int x, int y) {
    x += 10;
    y = -1 * y;
    y += 10;
    return objectGrid[x][y];
}
