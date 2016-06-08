#include <iostream>
#include <string>
#include "Bed.h"
#include "Furniture.h"
using namespace std;
//impelementation of Bed class

//constructor with calling Furniture superclass constructor
Bed::Bed(string newName, string newSize) : Furniture(newName) {
    size = newSize;
    //check for valid size
    if (size != "Twin" && size != "Full" && size != "Queen" && size != "King") {
        cout << "Invalid bed size";
        exit(0);
    }
    //promt user for the dimentions
    ReadDimentions();
}

//printing the dimensions with Furnitures Print
void Bed::Print() {
    Furniture::Print();
    //print Bed size
    cout << size << " size\n";
}

