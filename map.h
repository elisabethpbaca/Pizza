#ifndef _MAP
#define _MAP

#include "object.h"
#include "structure.h"

using namespace std;

class Map {
    private:
        int width, height;
        vector<Object*> objectGrid[20][20];
        vector<Structure*> structureGrid[20][20];

    public:
        Map(void);

        void add_object(Object*, int x, int y);

        vector<Object*> get_objects(int x, int y);
        vector<Structure*> get_structures(int x, int y);

        void delete_object(int x, int y, string itemName);
};


#endif
