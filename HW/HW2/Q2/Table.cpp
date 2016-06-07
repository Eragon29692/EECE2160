#include <iostream>
#include <string>
#include "Table.h"

using namespace std;

Table::Table(string newName, string woodType) : Furniture(newName) {
    wood = woodType;
    if (wood != "Pine" && wood != "Oak") {
        cout << "Invalid wood type";
        exit(0);
    }

    ReadDimentions();
}

void Table::Print() {
    Furniture::Print();
    cout << wood << " wood\n";
}

