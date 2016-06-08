#ifndef TABLE_H
#define TABLE_H
#include "Furniture.h"
#include <string>
#include <cstdlib>

using namespace std;
//table class declaration


class Table : public Furniture {
private:
    //wood type
    string wood;
public:
    //constructor
    Table(string newName, string woodType);
    //print the table dimensions and wood type
    void Print();
};


#endif

