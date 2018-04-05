#include <iostream>
#include <string>
#include "player.h"
#include "map.h"
#include "child.h"
#include "helpers.h"

using namespace std;

int main(void){
string command;
Object tempObject;
bool alive = 1;

    cout << ">";
    while(alive && getline(cin, command)) {

        command = to_lower(command);

        if(contains(command, "go", "walk", "head")) {
            move(command);
            cout << "You are at coordinates: " << P1.get_position() << endl;

        }else if(contains(command, "kill") && contains(command, "self", "myself", "yourself")) {
            if(contains(command, "rope")) {
                if(P1.search_inventory(cUtility, "rope")) {
                    cout << "You hung yourself" << endl;
                    alive = 0;
                }else {
                    cout << "You don't have a rope :(" << endl;
                }
            }else {
                cout << "Kill yourself with?" << endl;
            }

        }else if(contains(command, "take", "grab", "pick up")){
            get_object_here(command);

        }else if(contains(command, "inventory", "items")){
            P1.show_inventory();

        }else if(contains(command, "status", "health", "my status")){
            P1.show_stats();

        }else if(contains(command, "help")){
            show_help();

        }else {
            cout << "I'm not sure what you mean, type 'help' for directions." << endl;
        }

        cout << ">";
    }

    cout << "GAME OVER" << endl << endl;

}
