#ifndef CALCULATOR_H
#define CALCULATOR_H

class Bed : public Furniture {
private:
    string size;
public:
    Bed(string newName, string newSize);
    void Print();
};


#endif