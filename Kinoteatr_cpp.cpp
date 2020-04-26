#include <iostream>
#include <string>
#include <fstream>
#include "Film.h";
#include "Function.h";
using namespace std;
bool work=true;

int main()
{
    setlocale(LC_CTYPE, "Russian");
    char choice;
    cout << "Добро пожаловать в кинотеатр!!!" << endl << "Выберите действие" << endl;
    while (work) {
        choice = menu_select();
        switch (choice) {
        case 1: addfilm();
            break;
        case 2: listfilm();
            break;
        case 3: searchfilm();
            break;
        case 4: deletefilm();
            break;
        case 5: changefilm();
            break;
        case 6: exit(0);
            return 0;
        }
    }
    return 0;
}
    

