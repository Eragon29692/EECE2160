#include <iostream>
#include <string>
#include "Table.h"

using namespace std;
//table class implementation

//constructor with calling the Furniture superclass constructor
Table::Table(string newName, string woodType) : Furniture(newName) {
    wood = woodType;
    //check for valid wood type
    if (wood != "Pine" && wood != "Oak") {
        cout << "Invalid wood type";
        exit(0);
    }
    //promt for user dimensions
    ReadDimentions();
}

//printing the table dimensions
void Table::Print() {
    Furniture::Print();
    //printing table wood type
    cout << wood << " wood\n";
}


