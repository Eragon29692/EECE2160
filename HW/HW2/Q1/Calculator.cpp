#include <iostream>
#include <string>
#include "Calculator.h"
using namespace std;

//constructor
template<class T>
Calculator<T>::Calculator() {
    value1 = T();
    value2 = T();
}
//constructor
template<class T>
Calculator<T>::Calculator(T data1, T data2) {
    value1 = data1;
    value2 = data2;
}
//getValue1
template<class T>
T Calculator<T>::getValue1() {
    return value1;
}

//getValue2
template<class T>
T Calculator<T>::getValue2() {
    return value2;
}

//getSum with + operand
template<class T>
T Calculator<T>::getSum() {
    return value1 + value2;
}

//logocal And with && operand
template<class T>
int Calculator<T>::getLogicalAND() {
    return value1 && value2;
}

//comparison using > operand
template<class T>
bool Calculator<T>::isGreater() {
    return value1 > value2;
}
