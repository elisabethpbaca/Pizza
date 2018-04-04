#include "helpers.h"

using namespace std;

Map GAMEMAP;
Player P1;

string to_lower(string stringToLower) {
    for(int i = 0; i < stringToLower.size(); i++) {
        stringToLower.at(i) = tolower(stringToLower.at(i));
    }
    return stringToLower;
}

bool contains(string container, string str1) {
    return container.find(str1) != std::string::npos;
}

bool contains(string container, string str1, string str2) {
    return (container.find(str1) != std::string::npos
        || container.find(str2) != std::string::npos);
}

bool contains(string container, string str1, string str2, string str3) {
    return (container.find(str1) != std::string::npos
        || container.find(str2) != std::string::npos
        || container.find(str3) != std::string::npos);
}

bool contains(string container, string str1, string str2, string str3, string str4) {
    return (container.find(str1) != std::string::npos
        || container.find(str2) != std::string::npos
        || container.find(str3) != std::string::npos
        || container.find(str4) != std::string::npos);
}

bool contains(string container, string str1, string str2, string str3, string str4, string str5) {
    return (container.find(str1) != std::string::npos
        || container.find(str2) != std::string::npos
        || container.find(str3) != std::string::npos
        || container.find(str4) != std::string::npos
        || container.find(str5) != std::string::npos);
}

void get_object_here(string objectToGet) {
    vector<Object*> itemsHere = GAMEMAP.get_objects(P1.get_position().getX(), P1.get_position().getY());

    if(itemsHere.size() != 0) {
        for(int i = 0; i < itemsHere.size(); i++) {
            if(contains(objectToGet, to_lower(itemsHere.at(i)->get_name()))) {
                P1.add_to_inventory(itemsHere.at(i));
                GAMEMAP.delete_object(P1.get_position().getX(), P1.get_position().getY(), itemsHere.at(i)->get_name());
                cout << "You took the " << itemsHere.at(i)->get_name() << endl;
            }else {
                cout << "There is no " << objectToGet << " here." << endl;
            }
        }
    }
}

void see_obstacles_here(void) {
    vector<Structure*> structuresHere;
    int x, y;
    string direction;
    for(int i = 0; i < 4; i++){
        switch(i) {
            case 0:
                x = P1.get_position().getX();
                y = P1.get_position().getY() + 1;
                direction = "to your north.";
                break;
            case 1:
                x = P1.get_position().getX() + 1;
                y = P1.get_position().getY();
                direction = "to your east.";
                break;
            case 2:
                x = P1.get_position().getX();
                y = P1.get_position().getY() - 1;
                direction = "to your south.";
                break;
            case 3:
                x = P1.get_position().getX() - 1;
                y = P1.get_position().getY();
                direction = "to your west.";
                break;
        }
        structuresHere = GAMEMAP.get_structures(x, y);
        if(structuresHere.size() != 0) {
            for(int i = 0; i < structuresHere.size(); i++) {
                if(structuresHere.at(i)->get_class() == cWall) {
                    cout << "There is a wall " << direction << endl;
                }
            }
        }
    }
}

void see_objects_here(void) {
    vector<Object*> itemsHere = GAMEMAP.get_objects(P1.get_position().getX(), P1.get_position().getY());
    if(itemsHere.size() != 0) {
        for(int i = 0; i < itemsHere.size(); i++) {
            cout << "There is a " << itemsHere.at(i)->get_name() << " here." << endl;
        }
    }
    see_obstacles_here();
}

void move(string moveCommand) {
    vector<Structure*> structuresHere;

    if(contains(moveCommand, "north")) {
        bool blocked = 0;
        structuresHere = GAMEMAP.get_structures(P1.get_position().getX(), P1.get_position().getY() + 1);
        for(int i = 0; i < structuresHere.size(); i++) {
            if(structuresHere.at(i)->get_class() == cWall){
                cout << "Can't go north, a wall blocks your path." << endl;
                blocked = 1;
            }
        }
        if(!blocked) {
            P1.go_north();
        }
    }

    if(contains(moveCommand, "east")) {
        bool blocked = 0;
        structuresHere = GAMEMAP.get_structures(P1.get_position().getX() + 1, P1.get_position().getY());
        for(int i = 0; i < structuresHere.size(); i++) {
            if(structuresHere.at(i)->get_class() == cWall){
                cout << "Can't go east, a wall blocks your path." << endl;
                blocked = 1;
            }
        }
        if(!blocked) {
            P1.go_east();
        }
    }

    if(contains(moveCommand, "south")) {
        bool blocked = 0;
        structuresHere = GAMEMAP.get_structures(P1.get_position().getX(), P1.get_position().getY() - 1);
        for(int i = 0; i < structuresHere.size(); i++) {
            if(structuresHere.at(i)->get_class() == cWall){
                cout << "Can't go south, a wall blocks your path." << endl;
                blocked = 1;
            }
        }
        if(!blocked) {
            P1.go_south();
        }
    }

    if(contains(moveCommand, "west")) {
        bool blocked = 0;
        structuresHere = GAMEMAP.get_structures(P1.get_position().getX() - 1, P1.get_position().getY());
        for(int i = 0; i < structuresHere.size(); i++) {
            if(structuresHere.at(i)->get_class() == cWall){
                cout << "Can't go west, a wall blocks your path." << endl;
                blocked = 1;
            }
        }
        if(!blocked) {
            P1.go_west();
        }
    }

    see_objects_here();
}
