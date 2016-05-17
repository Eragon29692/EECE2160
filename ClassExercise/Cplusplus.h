#include <iostream>

using namespace std;

class Rectangle
{
private:
    int width;
	int length;
public:
	void setWidth(int w);
	void setLength(int l);
	int getWidth() { return width; }
	int getLength() { return length; }
	int getArea();
	void grow(int factor);
};
void Rectangle::setWidth(int w)
{
    width = w;
}
void Rectangle::setLength(int l)
{
    length = l;
}

 // Put the function definitions here
 
int main()
{
	Rectangle myRect;
	//myRect.setWidth(7);
	//myRect.setLength(3);

	cout << myRect.getWidth() << " * " << myRect.getLength() << " = ";
	cout <<  myRect.getArea() << endl;

	myRect.grow(3);
	cout << myRect.getWidth() << " * " << myRect.getLength() << " = ";
	cout <<  myRect.getArea() << endl;
}