#include <iostream>
#include <string>
using namespace std;


// Class Definition
template<class T> class VectorArray {
private:
    T *v; // Resizable vector
    int count; // The number of elements in the vector
    int size; // The capacity of the vector
public:
    VectorArray();		// Default Constructor
    ~VectorArray();	// Destructor

    void AddElement();
    void RemoveElement();
    void Grow();
    void Shrink();
    void InsertElement();
    void PrintVector();
};
/**
 * Constructor initialize the global variables
 *
 * @param  None	Default constructor does not need arguments.
 * @return	None Default constructor does not return anything.
 */
template<class T>
VectorArray<T>::VectorArray() {
    v = new T[2]; // Allocate enough memory for 2 elements
    count = 0; // There are no elements initially
    size = 2; // Initial capacity is 2
}

/**
 * Destructor releases the memory.
 *
 * @param  None	Destructor does not need arguments.
 * @return	None Destructor does not return anything.
 */
template<class T>
VectorArray<T>::~VectorArray() {
    delete[] v; // free the memory
}


/**
 * Add a new element to the end of the vector,
 * growing if necessary.
 *
 * @param None
 * @return	None
 */
template<class T>
void VectorArray<T>::AddElement()
{
    if (count == size) { // If there is no more space, grow
        Grow();
    }
    // Get the new element from the user
    cout << "Enter the new element: ";
    cin >> v[count++]; //Add the new element and update count
}


/**
 * Grow the vector to 2x current capacity.
 *
 * @param None
 * @return	None
 */
template<class T>
void VectorArray<T>::Grow()
{
    cout << "Vector grown" << endl;
    cout << "Previous capacity: " << size << " elements" << endl;
    size = size * 2; // Double the capacity
    cout << "New capacity: " << size << " elements" << endl;

    T *newv = new T[size]; // // Allocate new memory space
    // Copy the old elements to the new vector
    for (int i = 0; i < count; i++) {
        newv[i] = v[i];
    }
    // Free the memory associated with the old vector
    delete[] v;
    v = newv; // Assign v to the new block of memory
}


/**
 * Remove an element from the end of the vector.
 *
 * @param None
 * @return	None
 */
template<class T>
void VectorArray<T>::RemoveElement()
{
    if (count == 0) { // If no more element, print an error message
        cout << "ERROR: no elements to remove\n";
    } else {
        count--; // Update count
        if ((double) count / size < 0.3) { // If the vector drops below 30% capacity, Shrink()
            Shrink();
        }
    } // end if-else
}


/**
 * Shrinks the vector to 1/2 the current capacity.
 *
 * @param None
 * @return	None
 */
template<class T>
void VectorArray<T>::Shrink()
{
    cout << "Vector shrunk" << endl;
    cout << "Previous capacity: " << size << " elements" << endl;
    size = size / 2; // Double the capacity
    cout << "New capacity: " << size << " elements" << endl;

    T *newv = new T[size]; // // Allocate new memory space
    // Copy the old elements to the new vector
    for (int i = 0; i < count; i++) {
        newv[i] = v[i];
    }
    // Free the memory associated with the old vector
    delete[] v;
    v = newv; // Assign v to the new block of memory
}


/**
 * Inserts an element
 *
 * @param None
 * @return	None
 */
template<class T>
void VectorArray<T>::InsertElement() {
    int index;
    double newElement;
    // Get the index
    cout << "Enter the index of new element: ";
    cin >> index;
    // If the index is not in the valid range [0, count], print an error message
    if (index > count || index < 0) {
        cout << "ERROR: invalid index\n";
        return;
    }
    // Get the new element
    cout << "Enter the new element: ";
    cin >> newElement;
    if (count == size) { // If the vector is full, Grow()
        Grow();
    }
    // Shift all of the elements from index to the end of the vector down by 1
    for (int i = count - 1; i >= index; i--) {
        v[i+1] = v[i];
    }
    v[index] = newElement; // Insert the new element at index
    count++; // Update count
}


/**
 * Print all of the elements in the vector
 *
 * @param None
 * @return	None
 */
template<class T>
void VectorArray<T>::PrintVector() {
    if (count == 0) { // If no more element, print an error message
        cout << "List is empty\n";
    } else {
        // Prints all elements
        for (int i = 0; i < count; i++) {
            cout << "[" << i << "] = " << v[i] << endl;
        }
    }
    cout << endl;
}



/** Prints out and requests input choice from user */
int getChoice() {
    int choice;
    cout << "\nMAIN MENU:" << endl;
    cout << "\n[1] Print the array" << endl;
    cout << "[2] Append element at the end" << endl;
    cout << "[3] Remove last element" << endl;
    cout << "[4] Insert one element" << endl;
    cout << "[5] Exit" << endl;
    cout << "\nSelect an option: " << endl;
    cin >> choice;
    return choice;
}

/**
 * Operates the VectorArray LEDs and switches
 */
int main()
{

    VectorArray<string> vector; // create vector
    int choice;
    while (1) {
        choice = getChoice(); // selection menu

        switch (choice) { // Do the function associated with the selected option
        case 1:
            vector.PrintVector();
            break;
        case 2:
            vector.AddElement();
            break;
        case 3:
            vector.RemoveElement();
            break;
        case 4:
            vector.InsertElement();
            break;
        case 5:
            return 1;
        default:
            cout << "Invalid option!" << endl;
            break;
        }
    }

}
