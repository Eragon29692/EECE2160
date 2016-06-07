#ifndef CALCULATOR_H
#define CALCULATOR_H

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