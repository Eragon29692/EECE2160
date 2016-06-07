#ifndef TABLE_H
#define TABLE_H
#include "Furniture.h"
#include <string>
#include <cstdlib>

using namespace std;

class Table : public Furniture {
private:
    string wood;
public:
    Table(string newName, string woodType);
    void Print();
};


#endif
