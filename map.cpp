#include "map.h"
using namespace std;

Map::Map(void) {
    class Utility* rope = new class Utility;
    rope->set_name("rope");
    objectGrid[0][1].push_back(rope);
}

vector<Object*> Map::get_objects(int x, int y) {
    return objectGrid[x][y];
}
