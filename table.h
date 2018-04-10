#include <string>
#include <vector>

class Table {
    private:
        vector<string> keyWords;
        vector<void(*func)()> functions;

    public:
        Table();
        void add_row(string keyWord, void(*func)() function);

};
