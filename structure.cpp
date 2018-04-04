#include "structure.h"

using namespace std;

Structure::Structure(void) {
    structureType = None;
}

StructType Structure::get_class(void) {
    return structureType;
}

Wall::Wall(void) {
    structureType = cWall;
}
