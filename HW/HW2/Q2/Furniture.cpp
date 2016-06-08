#include <iostream>
#include <string>
#include "Furniture.h"
using namespace std;
//implementation of the Furniture class

//constructor
Furniture::Furniture(string newName) {
    name = newName;
}
//promt user for the Furniture Dimension
void Furniture::ReadDimentions() {
    //get width
    cout << "Enter width: ";
    cin >> width;
    //check for valid width
    if (width < 0) {
        cout << "not a valid dimention";
        exit(0);
    }
    //get height
    cout << "Enter height: ";
    cin >> height;
    //check for valid height
    if (height < 0) {
        cout << "not a valid dimention";
        exit(0);
    }
    //get depth
    cout << "Enter depth: ";
    cin >> depth;
    //check for valid depth
    if (depth < 0) {
        cout << "not a valid dimention";
        exit(0);
    }
}

//Print the Furniture dimensions
void Furniture::Print() {
    cout << "\n" << name << ":\n";
    cout << "Width = " << width << ", height = " << height << ", depth = " << depth << endl;
}



