#ifndef _STRUCTURE
#define _STRUCTURE


using namespace std;

enum StructType { Wall, Door, WindowedWall, Trapdoor, Stairs };

class Structure {
    private:
        StructType structureType;
        float durabilityPoints;
        bool isLocked;
        bool isDestructable;
    public:

};

#endif
