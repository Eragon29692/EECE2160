#ifndef FURNITURE_H
#define FURNITURE_H
#include <string>
#include <cstdlib>
using namespace std;

//Furniture class declaration
class Furniture {
private:
    //dimensions
    float width;
    float height;
    float depth;
    //name
    string name;
public:
    //constrcutor
    Furniture(string newName);
    //prmt user for the dimensions
    void ReadDimentions();
    //print the dimensions
    virtual void Print();
};


#endif

