#include <iostream>
#include <string>
#include "Calculator.h"

using namespace std;

class Arithmetic {
private:
    int intData;
    float floatData;
    double doubleData;
    template<class T2>
    void printOperation(T2 obj) {
        cout << obj.getValue1() << " + " << obj.getValue2() << " = " << obj.getSum();
        cout << obj.getValue1() << " && " << obj.getValue2() << " = " << obj.getLogicalAND();
        cout << obj.getValue1() << " > " << obj.getValue2() << " = " << obj.isGreater();
    }
public:
    Arithmetic() {
        intData = 0;
        floatData = 0;
        doubleData = 0;
    }

    Arithmetic(int i, float f, double d) {
        intData = i;
        floatData = f;
        doubleData = d;
    }

    int getInt() {
        return intData;
    }

    float getFloat() {
        return floatData;
    }

    double getDouble() {
        return doubleData;
    }

    void intOperations(Arithmetic obj) {
        Calculator<int> cal(intData, obj.getInt);
        printOperation(cal);
    }

    void floatOperations(Arithmetic obj) {
        Calculator<float> cal(intData, obj.getFloat);
        printOperation(cal);
    }

    void intOperations(Arithmetic obj) {
        Calculator<double> cal(intData, obj.getDouble);
        printOperation(cal);
    }

}