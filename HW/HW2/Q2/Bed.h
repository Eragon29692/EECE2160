#ifndef BED_H
#define BED_H
#include <string>
#include "Furniture.h"
#include <cstdlib>
using namespace std;

class Bed : public Furniture {
private:
    string size;
public:
    Bed(string newName, string newSize);
    void Print();
};


#endif
