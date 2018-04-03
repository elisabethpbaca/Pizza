#ifndef _MAP
#define _MAP

#include "object.h"

using namespace std;

class Map {
    private:
        int width, height;
        Object objectGrid[20][20];
        //Structure structureGrid[20][20];

    public:
        Map(void);

        Object get_object(int x, int y);
};


#endif
