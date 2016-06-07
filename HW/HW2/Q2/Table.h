#ifndef CALCULATOR_H
#define CALCULATOR_H

class Table : public Furniture {
private:
    string wood;
public:
    Table(string newName, string woodType);
    void Print();
};


#endif