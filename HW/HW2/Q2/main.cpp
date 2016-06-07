#include <iostream>
#include <string>
#include "Furniture.h"
#include "Table.h"
#include "Bed.h"
using namespace std;

int main() {
	string tableName;
	string woodType;
	string bedName;
	string size;
	
	cout << "\n\nCreating table...\n";
	cout << "Enter name: ";
	cin >> tableName;
	cout << "Enter wood type: ";
	cin >> woodType;
	Table table(tableName, woodType);
	
		
	cout << "\n\nCreating Bed...\n";
	cout << "Enter name: ";
	cin >> bedName;
	cout << "Enter bed size: ";
	cin >> size;
	Bed bed(bedName, size);
	
	cout << "\n\nPrinting objects ...\n\n";
	
	table.Print();
	bed.Print();
	
}
