#include <iostream>
#include <string>

using namespace std;

template<class T> class Student
{
private:
	T data1;
	T data2;
public:
	Student() {data1 = T(); data2 = T();}
	Student(T value1, T value2);
	T getSum();
};

template<class T>
Student<T>::Student(T value1, T value2)
{
	data1 = value1;
	data2 = value2;
}

template<class T>
T Student<T>::getSum()
{
	T sum = data1 + data2;
	return sum;
}

int main()
{
	int a = 85;
	int b = 72;
	Student<int> myStudent(a, b);
	cout << a << " + " << b << " = " << myStudent.getSum();
	cout << endl;
}

