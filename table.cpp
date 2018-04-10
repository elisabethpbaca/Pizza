#include "table.h"
#include "helpers.h"

Table::Table() {

    add_row("go", move);

}

void Table::add_row(string keyWord, void (*func)() function) {
    keyWords.push_back(keyWord);
    functions.push_back(function);
}


for(int i = 0; i < Table.size(); i++){
    if(contains(command, Table.get_keywords().at(i))) {
        Table.get_func().at(i)();
    }
}
