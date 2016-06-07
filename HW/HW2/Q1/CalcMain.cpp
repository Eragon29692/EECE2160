#include <iostream>
#include <string>
#include "Calculator.h"
#include "Calculator.cpp"
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
        Calculator<int> cal(intData, obj.getInt());
        printOperation<Calculator<int> >(cal);
    }

    void floatOperations(Arithmetic obj) {
        Calculator<float> cal(floatData, obj.getFloat());
        printOperation(cal);
    }

    void doubleOperations(Arithmetic obj) {
        Calculator<double> cal(doubleData, obj.getDouble());
        printOperation(cal);
    }

};


int main()
{
// Create 1st object
int int1 = 4;
float f1 = 10.4;
double d1 = 20.1;
Arithmetic object1(int1, f1, d1);
// Create 2nd object
int int2 = 7;
float f2 = 0.0;
double d2 = 3.5;
Arithmetic object2(int2, f2, d2);
// Check operation on integer data type
cout << "\nPrinting INTEGER operations..." << endl;
object1.intOperations(object2);
// Check operation on float data type
cout << "\nPrinting FLOAT operations..." << endl;
object1.floatOperations(object2);
// Check operation on double data type
cout << "\nPrinting DOUBLE operations..." << endl;
object1.doubleOperations(object2);
} // end main

