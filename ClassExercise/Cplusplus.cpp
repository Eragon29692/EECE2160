#include <iostream>

using namespace std;

class Rectangle
{
    private:
        int width;
        int length;
    public:
	Rectangle() {
	    width = length = 5;
	}
        Rectangle(int w, int l);
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

int Rectangle::getArea() 
{
    return width * length;
}

void Rectangle::grow(int factor)
{
    width = width * factor;
    length = length * factor;
}

Rectangle::Rectangle(int w, int l)
{
    width = w;
    length = l;
}

 
int main()
{
	Rectangle myRect(7, 3);
	Rectangle myRect2;
	//myRect.setWidth(7);
	//myRect.setLength(3);

	cout << myRect.getWidth() << " * " << myRect.getLength() << " = ";
	cout <<  myRect.getArea() << endl;

	myRect.grow(3);
	cout << myRect.getWidth() << " * " << myRect.getLength() << " = ";
	cout <<  myRect.getArea() << endl;

	cout << myRect2.getWidth() << " * " << myRect2.getLength() << " = ";
	cout <<  myRect2.getArea() << endl;

}
