#include <iostream>
#include <string>
#include "player.h"
#include "map.h"
#include "child.h"

using namespace std;

// Constants

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
    vector<Object> itemsHere = GAMEMAP.get_objects(P1.get_position().getX(), P1.get_position().getY());
    if(itemsHere.size() != 0) {
        for(int i = 0; i < itemsHere.size(); i++) {
            if(contains(objectToGet, itemsHere.at(i).get_name())) {
                P1.add_to_inventory(itemsHere.at(i));
                cout << "You took the " << objectToGet << endl;
            }else {
                cout << "There is no " << objectToGet << " here." << endl;
            }
        }
    }
}

void see_objects_here() {
    vector<Object> itemsHere = GAMEMAP.get_objects(P1.get_position().getX(), P1.get_position().getY());
    if(itemsHere.size() != 0) {
        for(int i = 0; i < itemsHere.size(); i++) {
            cout << "There is a " << itemsHere.at(i).get_name() << " here." << endl;
        }
    }
}


int main(void){

string command;
Object tempObject;
bool alive = 1;

    while(alive && getline(cin, command)) {

        command = to_lower(command);

        if(contains(command, "go", "walk", "head")) {

            if(contains(command, "north")) {
                P1.go_north();
                see_objects_here();

            }else if(contains(command, "east")) {
                P1.go_east();
                see_objects_here();

            }else if(contains(command, "south")) {
                P1.go_south();
                see_objects_here();

            }else if(contains(command, "west")) {
                P1.go_west();
                see_objects_here();

            }
            cout << "You are at coordinates: " << P1.get_position() << endl;
        }else if(command.find("kill") != std::string::npos && (command.find("yourself") != std::string::npos || command.find("myself") != std::string::npos)){
            if(command.find("rope") != std::string::npos){
                if(P1.search_inventory(Utility, "rope")) {
                    cout << "You hung yourself" << endl;
                    alive = 0;
                }else {
                    cout << "You don't have a rope :(" << endl;
                }
            }else {
                cout << "Kill yourself with what?" << endl;
            }
        }else if(contains(command, "take", "grab", "pick up")){
            get_object_here(command);

        }else {
            cout << "I'm not sure what you mean" << endl;
        }

    }

    cout << "GAME OVER" << endl << endl;

}
