#include <iostream>
#include <string>
#include "Calculator.h"
using namespace std;


template<class T>
Calculator<T>::Calculator() {
    data1 = T();
    data2 = T();
}

template<class T>
Calculator<T>::Calculator(T data1, T data2) {
    value1 = data1;
    value2 = data2;
}

template<class T>
T Calculator<T>::getValue1() {
    return value1;
}


template<class T>
T Calculator<T>::getValue2() {
    return value2;
}


template<class T>
T Calculator<T>::getSum() {
    return value1 + value2;
}


template<class T>
int Calculator<T>::getLogicalAND() {
    return value1 && value2;
}


template<class T>
bool Calculator<T>::isGreater() {
    return value1 > value2;
}