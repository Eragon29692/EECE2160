#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <stdlib.h>
#include <sys/mman.h>
using namespace std;


class Car {
	private:
		string make;
		string model;
		int year;
		string color;
	public:
		Car() {
			make = "";
			model = "";
			year = 0;
			color = ""
		}
		
		setFields(string mk, string md, int yr,string cl) {
			make = mk;
			model = md;
			year = yr;
			color = cl;
		}
		
		string getMake() {
			return make;
		}
		
		string getModel() {
			return model;
		}
		
		string getYear() {
			return to_string(year);
		}
		
		string getColor() {
			return color;
		}	
};

class CarRecords {
	private:
		int arraySize;
		ifsteam infile;
		Car *cars;
	public:
		CarRecords(int size) {
			infile.open("CarRecords.txt");
			if (!infile) {
				cout << "Can't open file CarRecords.txt"
				exit(0);
			}
			if (size > 10) {
				size = 10;
			}
			cars = new Car[size];
			arraySize = size;
			
			for (int i = 0; i < arraySize; i++) {
				infile >> *(cars + i).make;
				infile >> *(cars + i).model;
				infile >> *(cars + i).year;
				infile >> *(cars + i).color;
			}
		}
		
		~CarRecords() {
			free(cars);
		}
		
		void printCarRecords () {
			cout << "PRINTING " << i 
			<< " RECORDS!---------------------\n";
			for (int i = 0; i < arraySize; i++) {
				cout << *(cars + i).make << ", "
				<< *(cars + i).model << ", "
				<< *(cars + i).year << ", "
				<< *(cars + i).color << "\n"
			}
		}
};

int main() {
	int numRecs;
	cout << "Number or Records to read? " ;
	cin >> numRecs;
	CarRecords *cr = new CarRecords(numRecs); 
	// Print car records
	cr->printCarRecords();
}
