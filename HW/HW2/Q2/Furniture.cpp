#include <iostream>
#include <string>
#include "Furniture.h"
using namespace std;

Furniture::Furniture(string newName) {
    name = newName;
}

void Furniture::ReadDimentions() {
    cout << "Enter width: ";
    cin >> width;
    if (width < 0) {
        cout << "not a valid dimention";
        exit(0);
    }
    cout << "Enter height: ";
    cin >> height;
    if (height < 0) {
        cout << "not a valid dimention";
        exit(0);
    }
    cout << "Enter depth: ";
    cin >> depth;
    if (depth < 0) {
        cout << "not a valid dimention";
        exit(0);
    }
}

void Furniture::Print() {
    cout << "\n" << name << ":\n";
    cout << "Width = " << width << ", height = " << height << ", depth = " << depth << endl;
}


