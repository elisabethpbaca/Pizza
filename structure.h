#ifndef _STRUCTURE
#define _STRUCTURE

#include "child.h"

using namespace std;

class Structure {
    protected:
        StructType structureType;
    public:
        // Constructors
        Structure(void);

        // Getters
        StructType get_class(void);

};

class Wall : public Structure {
    private:

    public:
        // Constructors
        Wall(void);
};

class Foliage : public Structure {
    private:

    public:
        // Constructors
        Foliage(void);
};


#endif
