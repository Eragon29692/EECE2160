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
        infile.close();
        delete [] cars;
    }


    void printCar(Car *car) {
        cout << car->getMake() << " , "
             << car->getModel() << " , "
             << car->getYear() << " , "
             << car->getColor() << "\n";
    }


    void printCarRecords () {
        int i;
        cout << "\nPRINTING " << arraySize
             << " RECORDS!---------------------\n";
        for (i = 0; i < arraySize; i++) {
            printCar(cars + i);
        }
    }

    void sort_cars_by_make() {
        int i, j;
        cout << "\n\nSORT CAR BY MAKE...\n";
        for (i = 0; i < arraySize; i++) {
            for (j = 0; j < arraySize - i - 1; j++) {
                if ((cars + j)->getMake() > (cars + j + 1)->getMake()) {
                    Car *temp = new Car();
                    *temp = *(cars + j);
                    *(cars + j) = *(cars + j + 1);
                    *(cars + j + 1) = *temp;
                }
            }
        }
    }



    void sort_cars_by_year() {
        int i, j;
        cout << "\n\nSORT CAR BY YEAR...\n";
        for (i = 0; i < arraySize; i++) {
            for (j = 0; j < arraySize - i - 1; j++) {
                if ((cars + j)->getYear() > (cars + j + 1)->getYear()) {
                    Car *temp = new Car();
                    *temp = *(cars + j);
                    *(cars + j) = *(cars + j + 1);
                    *(cars + j + 1) = *temp;
                }
            }
        }
    }


    void print_duplicates() {
        int i, j;
        cout << "\n\nCHECKING FOR DUPLICATES...\n";
        for (i = 0; i < arraySize; i++) {
            for (j = i + 1; j < arraySize; j++) {
                if ((cars + i)->getMake() == (cars + j)->getMake()
                        && (cars + i)->getModel() == (cars + j)->getModel()
                        && (cars + i)->getYear() == (cars + j)->getYear()
                        && (cars + i)->getColor() == (cars + j)->getColor()) {
                    printCar(cars + i);
                    printCar(cars + j);
                }
            }
        }
        cout << "\nDone\n\n";
    }
	
};

int main() {
    int numRecs;
    cout << "\n\nNumber or Records to read? " ;
    cin >> numRecs;
    CarRecords *cr = new CarRecords(numRecs);


    // Print car records
    cr->printCarRecords();
    // Sort by Year
    cr->sort_cars_by_year();
    // Print car records
    cr->printCarRecords();
    // Sort by Make
    cr->sort_cars_by_make();
    // Print car records
    cr->printCarRecords();
    // Check for Duplicates
    cr->print_duplicates();


    delete cr;
}



