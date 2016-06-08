#include <iostream>
#include <string>
#include "Furniture.h"
#include "Table.h"
#include "Bed.h"
using namespace std;
//main functions


int main() {
    string tableName;
    string woodType;
    string bedName;
    string size;
    //promt for table name
    cout << "\n\nCreating table...\n";
    cout << "Enter name: ";
    cin >> tableName;
    //promt for table wood type
    cout << "Enter wood type: ";
    cin >> woodType;
    //creating table
    Table table(tableName, woodType);

    //promt for bed name
    cout << "\n\nCreating Bed...\n";
    cout << "Enter name: ";
    cin >> bedName;
    //promt bed size
    cout << "Enter bed size: ";
    cin >> size;
    //creating bed
    Bed bed(bedName, size);

    //starting printing the objects
    cout << "\n\nPrinting objects ...\n\n";

    //print the objects
    table.Print();
    bed.Print();

}

