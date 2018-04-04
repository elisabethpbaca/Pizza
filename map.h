#ifndef _MAP
#define _MAP

#include "object.h"

using namespace std;

class Map {
    private:
        int width, height;
        vector<Object> objectGrid[20][20];

    public:
        Map(void);

        vector<Object> get_objects(int x, int y);
};


#endif
