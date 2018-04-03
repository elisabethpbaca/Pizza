#include <iostream>
#include <string>
#include "player.h"
#include "map.h"

using namespace std;



int main(void){

string command;
Map gameMap;
Player P1;
Object tempObject;
bool alive = 1;

    while(alive && getline(cin, command)) {

        for(int i = 0; i < command.size(); i++) {
            command.at(i) = tolower(command.at(i));
        }

        if(command.find("go") != std::string::npos || command.find("walk") != std::string::npos || command.find("head") != std::string::npos){

            if(command.find("north") != std::string::npos) {
                P1.go_north();
                tempObject = gameMap.get_object(P1.get_position().getX(), P1.get_position().getY());
                if(tempObject.get_item_type() != 5){
                    cout << "There is a " << tempObject.get_item() << " here." << endl;
                }
            }else if(command.find("east") != std::string::npos) {
                P1.go_east();
                tempObject = gameMap.get_object(P1.get_position().getX(), P1.get_position().getY());
                if(tempObject.get_item_type() != 5){
                    cout << "There is a " << tempObject.get_item() << " here." << endl;
                }
            }else if(command.find("south") != std::string::npos) {
                P1.go_south();
                tempObject = gameMap.get_object(P1.get_position().getX(), P1.get_position().getY());
                if(tempObject.get_item_type() != 5){
                    cout << "There is a " << tempObject.get_item() << " here." << endl;
                }
            }else if(command.find("west") != std::string::npos) {
                P1.go_west();
                tempObject = gameMap.get_object(P1.get_position().getX(), P1.get_position().getY());
                if(tempObject.get_item_type() != 5){
                    cout << "There is a " << tempObject.get_item() << " here." << endl;
                }
            }
            cout << "You are at coordinates: " << P1.get_position() << endl;
        }else if(command.find("kill") != std::string::npos && (command.find("yourself") != std::string::npos || command.find("myself") != std::string::npos)){
            if(command.find("rope") != std::string::npos){
                if(P1.search_inventory(1, "rope")) {
                    cout << "You hung yourself" << endl;
                    alive = 0;
                }else {
                    cout << "You don't have a rope :(" << endl;
                }
            }else {
                cout << "Kill yourself with what?" << endl;
            }
        }else if(command.find("take") != std::string::npos && command.find(tempObject.get_item()) != std::string::npos){
            P1.add_to_inventory(tempObject);
            cout << "You took the " << tempObject.get_item() << endl;
        }else {
            cout << "I'm not sure what you mean" << endl;
        }

    }

    cout << "GAME OVER" << endl << endl;

}
