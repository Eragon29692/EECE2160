#ifndef BED_H
#define BED_H
#include <string>
#include "Furniture.h"
#include <cstdlib>
using namespace std;

//class Bed declaration
class Bed : public Furniture {
private:
    //Bed size
    string size;
public:
    //constructor
    Bed(string newName, string newSize);
    //print the dimentions and size of the Bed
    void Print();
};


#endif

