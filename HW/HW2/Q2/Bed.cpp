#include <iostream>
#include <string>
#include "Bed.h"
#include "Furniture.h"
using namespace std;

Bed::Bed(string newName, string newSize) : Furniture(newName) {
    size = newSize;
    if (size != "Twin" && size != "Full" && size != "Queen" && size != "King") {
        cout << "Invalid bed size";
        exit(0);
    }
    ReadDimentions();
}

void Bed::Print() {
cout << "\nMyBed:\n";
    Furniture::Print();
    cout << size << " size\n";
}