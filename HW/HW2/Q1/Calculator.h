#ifndef CALCULATOR_H
#define CALCULATOR_H

//class template
template<class T> class Calculator
{
private:
    //private data member
    T value1;
    T value2;
public:
    //constructors
    Calculator();
    Calculator(T value1, T value2);
    //getters
    T getValue1();
    T getValue2();
    //getSum with + operand
    T getSum();
    //and logical with && operand
    int getLogicalAND();
    //comparison with > operand
    bool isGreater();
};

#endif

