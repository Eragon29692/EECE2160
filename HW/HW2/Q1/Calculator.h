#ifndef CALCULATOR_H
#define CALCULATOR_H

template<class T> class Calculator
{
private:
	T value1;
	T value2;
public:
	Calculator();
	Calculator(T value1, T value2);
	T getValue1();
	T getValue2();
	T getSum();
	int getLogicalAND();
	bool isGreater();
};

#endif
