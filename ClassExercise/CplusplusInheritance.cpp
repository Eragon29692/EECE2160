#include <iostream>
#include <string>
using namespace std;

/****************** Class Pet ***********************/
class Pet {
private:
	//private data members
	string name;
	int age;
public:
	//public data members
	Pet();					// Default constructor
	Pet(string theName, int theAge);	// Constructor
	string getName() {
		return name;
	}
	int getAge() {
		return age;
	}
	void setName(string theName) {
		name = theName;
	}
	void setAge(int theAge) {
		age = theAge;
	}
	void printPet();			// print pets information
	//virtual string petSound() = 0; 	// virtual function must be implemented
						// in derived classes
};

// Default Pet constructor initializes member data to default values
Pet::Pet() {
	name = "No name";
	age = 0;
}

// Constructor initializes member data
Pet::Pet(string theName, int theAge) {
	name = theName;
	age = theAge;
}

// Print pets information
void Pet::printPet() {
	cout << " Name of pet - " << name << endl;
	cout << " Age of pet - " << age << endl;
} // end class

/*** Write a class Dog that inherits from class Pet here**/

class Dog : public Pet {
    private:
        string breed;
    public:
        Dog() : breed("Breed Unknown"){}
        Dog(string theName, int theAge, string theBreed) : Pet(theName, theAge) {
	    breed = theBreed;
	}
	string getBreed() { return breed; }
        void setBreed(string theBreed) { breed = theBreed; }
	void printDog() { printPet(); };    
};  




/* 	
 * Name: main function
 * the main function is the driver to test the functionality of the classes
 */
int main() {

	Dog dog1; 			// Calls default constructors	
	cout << "Dog1's default values from default constructors:" << endl;
	dog1.printDog(); 	// Prints out name, age and breed of dog

	cout << "\nDog1's new values:" << endl;
	dog1.setName("Cooper");  	// Gives dog1 a name
	dog1.setAge(5);			// Gives dog1 an age
	dog1.setBreed("Poodle");	// Gives dog1 a breed name
	dog1.printDog();		// Prints out dog1 information,

	Dog dog2("Buddy", 10, "Husky"); // Creates and initializes dog2
	cout << "\nDog2's values initialized by both constructors:" << endl;
	dog2.printDog();			// Prints out dog2 information,

	// Get dog2's information 
	cout << endl;
	cout << dog2.getName() << " is a " << dog2.getAge();
	cout << " year old " << dog2.getBreed() << endl << endl;
        
       // Get dog2's information with petSound()
        
        //cout << dog2.getName() << " is a " << dog2.getAge();
        //cout << " year old " << dog2.getBreed() << " who " << dog2.petSound() << endl;

} // end main

