#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <stdlib.h>
#include <sys/mman.h>
#include <fstream>
#include <string>

using namespace std;

//class Car
class Car {
private:
    //car's properties
    string make;
    string model;
    int year;
    string color;
public:
    //constructor
    Car() {
        make = "";
        model = "";
        year = 0;
        color = "";
    }
    //set the fields to the desired values
    void setFields(string mk, string md, int yr,string cl) {
        make = mk;
        model = md;
        year = yr;
        color = cl;
    }
    //return make
    string getMake() {
        return make;
    }
    //return model
    string getModel() {
        return model;
    }
    //return year
    int getYear() {
        return year;
    }
    //get color
    string getColor() {
        return color;
    }
};


//class CarRecords
class CarRecords {
private:
    int arraySize;
    ifstream infile;
    Car *cars;
public:
    //constructor
    CarRecords(int size) {
        //open file
        infile.open("CarRecords.txt");
        //check if the file exist
        if (!infile) {
            cout << "Can't open file CarRecords.txt";
            exit(0);
        }
        //set the number of records to read to 10 if user enter > 10
        if (size > 10) {
            size = 10;
        }
        //initialize the cars pointer to a car array
        cars = new Car[size];
        //set the size of the car array
        arraySize = size;
		
        //inserting texts to the array, line by line
        for (int i = 0; i < arraySize; i++) {
            string make;
            string model;
            int year;
            string color;
			
            //get make from file
            infile >> make;
            //delete the last comma from make
            make.erase(make.size() - 1);
            //get model from file
            infile >> model;
            //delete the ending comma from model
            model.erase(model.size() - 1);
            //get year
            infile >> year;
            //get then throw away the comma after the year
            infile >> color;
            //get the actual color from file
            infile >> color;
            //set the fields to the ith element of the array
            (cars + i)->setFields(make, model, year, color);
        }
    }


    //destructor
    ~CarRecords() {
        //close file
        infile.close();
        //free up cars array memory
        delete [] cars;
    }

    //print a car object
    void printCar(Car *car) {
        cout << car->getMake() << " , "
             << car->getModel() << " , "
             << car->getYear() << " , "
             << car->getColor() << "\n";
    }

    //print the array of cars
    void printCarRecords () {
        int i;
        cout << "\nPRINTING " << arraySize
             << " RECORDS!---------------------\n";
        //for loop to print all the cars in the array
        for (i = 0; i < arraySize; i++) {
            printCar(cars + i);
        }
    }


    //sort the cars by make
    void sort_cars_by_make() {
        int i, j;
        cout << "\n\nSORT CAR BY MAKE...\n";
        //bubble sort
        for (i = 0; i < arraySize; i++) {
            for (j = 0; j < arraySize - i - 1; j++) {
                //check for make
                if ((cars + j)->getMake() > (cars + j + 1)->getMake()) {
                    //make a temp car pointer to swap the 2 car records
                    Car *temp = new Car();
                    //point temp to the first car
                    *temp = *(cars + j);
                    //point the first car to the second car
                    *(cars + j) = *(cars + j + 1);
                    //point the second car to temp
                    *(cars + j + 1) = *temp;
                }
            }
        }
    }


    //sort the cars by year

    //Same as above
    void sort_cars_by_year() {
        int i, j;
        cout << "\n\nSORT CAR BY YEAR...\n";
        //bubble sort
        for (i = 0; i < arraySize; i++) {
            for (j = 0; j < arraySize - i - 1; j++) {
                //compare 2 years for swapping
                if ((cars + j)->getYear() > (cars + j + 1)->getYear()) {
                    //create a temp position
                    Car *temp = new Car();
                    //point the temp to the first car
                    *temp = *(cars + j);
                    //point the first to the second
                    *(cars + j) = *(cars + j + 1);
                    //point the second to temp
                    *(cars + j + 1) = *temp;
                }
            }
        }
    }



    //print duplicated records
    void print_duplicates() {
        int i, j;
        cout << "\n\nCHECKING FOR DUPLICATES...\n";

        //check each record with the rest
        for (i = 0; i < arraySize; i++) {
            for (j = i + 1; j < arraySize; j++) {
                //check between the 2 records
                if ((cars + i)->getMake() == (cars + j)->getMake()
                        && (cars + i)->getModel() == (cars + j)->getModel()
                        && (cars + i)->getYear() == (cars + j)->getYear()
                        && (cars + i)->getColor() == (cars + j)->getColor()) {
                    //print them both out if similar
                    printCar(cars + i);
                    printCar(cars + j);
                }
            }
        }
        cout << "\nDone\n\n";
    }

};




//main function
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




