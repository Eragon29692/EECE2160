#ifndef FURNITURE_H
#define FURNITURE_H
#include <string>
#include <cstdlib>
using namespace std;

class Furniture {
private:
    float width;
    float height;
    float depth;
    string name;
public:
    Furniture(string newName);
    void ReadDimentions();
    virtual void Print();
};


#endif
