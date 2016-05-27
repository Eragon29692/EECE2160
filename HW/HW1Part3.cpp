#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <stdlib.h>
#include <sys/mman.h>
#include <fstream>
#include <string>

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
        color = "";
    }

    void setFields(string mk, string md, int yr,string cl) {
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

    int getYear() {
        return year;
    }

    string getColor() {
        return color;
    }
};

class CarRecords {
private:
    int arraySize;
    ifstream infile;
    Car *cars;
public:
    CarRecords(int size) {
        infile.open("CarRecords.txt");
        if (!infile) {
            cout << "Can't open file CarRecords.txt";
            exit(0);
        }
        if (size > 10) {
            size = 10;
        }
        cars = new Car[size];
        arraySize = size;

        for (int i = 0; i < arraySize; i++) {
            string make;
            string model;
            int year;
            string color;
            infile >> make;
            make.erase(make.size() - 1);
            infile >> model;
            model.erase(model.size() - 1);
            infile >> year;
            infile >> color;
            infile >> color;
            (cars + i)->setFields(make, model, year, color);
        }
    }

    ~CarRecords() {
        free(cars);
    }

    void printCarRecords () {
        int i;
        cout << "\nPRINTING " << arraySize
             << " RECORDS!---------------------\n";
        for (i = 0; i < arraySize; i++) {
            cout << (cars + i)->getMake() << " , "
                 << (cars + i)->getModel() << " , "
                 << (cars + i)->getYear() << " , "
                 << (cars + i)->getColor() << "\n";
        }
    }

    void sort_cars_by_make() {
        int i, j;
        for (i = 0; i < 10; i++) {
            for (j = 0; j < 10 - i - 1; j++) {
                if ((cars + j)->getMake() > (cars + j + 1)->getMake()) {
                    Car *temp = new Car();
		    *temp = *(cars + j);
                    *(cars + j) = *(cars + j + 1);
                    *(cars + j + 1) = *temp;
                }
            }
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



    // Sort by Make
    cr->sort_cars_by_make();
    // Print car records
    cr->printCarRecords();
}


