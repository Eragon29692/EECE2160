#include <iostream>
#include <string>
#include "Calculator.h"
#include "Calculator.cpp"
using namespace std;


//class Arithmetic
class Arithmetic {
private:

    //private variables
    int intData;
    float floatData;
    double doubleData;

    //template function for printing operations
    template<class T2>
    void printOperation(T2 obj) {

        //printing getSum
        cout << obj.getValue1() << " + " << obj.getValue2() << " = " << obj.getSum() << endl;

        //printing and operation
        cout << obj.getValue1() << " && " << obj.getValue2() << " = " << obj.getLogicalAND() << endl;

        //printing isGreater operation
        cout << obj.getValue1() << " > " << obj.getValue2() << " = ";
        if (obj.isGreater())
            cout << "true";
        else
            cout << "false";

        //printing ending to newline
        cout << endl;
    }
public:

    //constructor
    Arithmetic() {
        intData = 0;
        floatData = 0;
        doubleData = 0;
    }
    //initiation in constructor
    Arithmetic(int i, float f, double d) {
        intData = i;
        floatData = f;
        doubleData = d;
    }
    //getInt for accessing intData
    int getInt() {
        return intData;
    }
    //getFloat for accessing floatData
    float getFloat() {
        return floatData;
    }
    //getDouble for accessing doubleData
    double getDouble() {
        return doubleData;
    }
    //calling int operations
    void intOperations(Arithmetic obj) {
        Calculator<int> cal(intData, obj.getInt());
        printOperation<Calculator<int> >(cal);
    }
    //calling float operations
    void floatOperations(Arithmetic obj) {
        Calculator<float> cal(floatData, obj.getFloat());
        printOperation(cal);
    }
    //calling double operation
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


