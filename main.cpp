#include <iostream>
#include <string>
#include "player.h"

using namespace std;



int main(void){

string command;
Player P1;

    while(getline(cin, command) ) {

        for(int i = 0; i < command.size(); i++) {
            command.at(i) = tolower(command.at(i));
        }

        if(command.find("go") != std::string::npos || command.find("walk") != std::string::npos || command.find("head") != std::string::npos){

            if(command.find("north") != std::string::npos) {
                P1.go_north();
            }else if(command.find("east") != std::string::npos) {
                P1.go_east();
            }else if(command.find("south") != std::string::npos) {
                P1.go_south();
            }else if(command.find("west") != std::string::npos) {
                P1.go_west();
            }
            cout << "You are at coordinates: " << P1.get_position() << endl;
        }else {
            cout << "I'm not sure what you mean" << endl;
        }

    }

}
