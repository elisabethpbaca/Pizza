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

void see_objects_here() {
    vector<Object*> itemsHere = GAMEMAP.get_objects(P1.get_position().getX(), P1.get_position().getY());
    if(itemsHere.size() != 0) {
        for(int i = 0; i < itemsHere.size(); i++) {
            cout << "There is a " << itemsHere.at(i)->get_name() << " here." << endl;
        }
    }
}

void move(string moveCommand) {
    if(contains(moveCommand, "north")) {
        P1.go_north();
    }
    if(contains(moveCommand, "east")) {
        P1.go_east();
    }
    if(contains(moveCommand, "south")) {
        P1.go_south();
    }
    if(contains(moveCommand, "west")) {
        P1.go_west();
    }
    see_objects_here();
}
