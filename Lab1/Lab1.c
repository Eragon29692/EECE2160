#include <stdio.h>
#include <stdlib.h>

//Global variable for the vector
double *v;
int count;
int size;

//Declarations the functions for vector
void Initialize();
void Finalize();
void Grow();
void AddElement();
void PrintVector();
void RemoveElement();
void InsertElement();
void Shrink();

//Implementation of Initialize
//initialize the values and allocate memory space for the vector
void Initialize() {
    count = 0;
    size = 2;
    v = malloc(2 * sizeof(double));
}

//Implementation of Finalize
//Free up the memory space that the vector point to
void Finalize() {
    free(v);
}


//Implementation of Grow
void Grow() {
    //allocating new memory region
    double *newVector;
    newVector = malloc(size * 2 * sizeof(double));

    //copying elements to the new vector
    int i;
    for (i = 0; i < count; i++) {
        *(newVector + i) = *(v + i); 
    }

    //free up the old memory space
    free(v);

    //point the old vector pointer to the new memory region
    v = newVector;

    //print the previous size
    printf("previous capacity: %d\n", size);
    //adjust and print the new vector's size
    size = size * 2;
    printf("new capacity: %d\n",size);
}



//Implementation of Add Element
void AddElement(){
    //reading a new number from the user
    double newelem;
    printf("Enter a new element: ");
    scanf("%lf", &newelem);
    
    //if there is no more space, grow the vector first
    if (count == size){
        Grow();
    }

    //add new element at the end of the vector
    *(v + count) = newelem;

    //adjust vector's count
    count++;
}


//prints the whole vector
void PrintVector(){
    //print the array using a for loop
    int i;
    printf("You have selected to print the array:\n ");
    for (i = 0; i < count - 1; i++){
        printf("%g, ",*(v + i));
    }
    //print the last element seperatly to avoid the ending comma
    if (count > 0) {
     printf("%g\n", *(v + i));
    }
}


//Implementation of remove element
void RemoveElement(){
    //flag for empty vector 
    if (count == 0){
        printf("You can not delete a vector that is empty\n");
        return;
    }
    //reduce count to "remove" the last element
    count  = count - 1;
    //Shrink the vector if less than 30%
    Shrink();
}


//Implementation of insert element
//notice we are using index from 1st -> nth not from 0 for ease of use
void InsertElement(){
    int placement;
    double newelem;
    int i;
    //grow the vector first if there is no empty space
    if (count == size){
        Grow();
    }
    
    //promt for user input
    printf("Enter the index of the new element (1 -> %d):", count + 1);
    scanf("%d",&placement);\
    
    //flag for invalid insert position
    if (placement > count + 1 || placement <= 0) {
        printf("you can not add elements outside the boundaries of the array\n");
        return;
    }

    //promt user for new element
    printf("Enter the new element:");
    scanf("%lf",&newelem);

    //move all the elements from the right of the insert 
    for (i = count - 1; i >= placement - 1; i--){
        *(v + i + 1) = *(v + i);
    }

    //insert the new element 
    *(v + placement - 1) = newelem;

    //adjusting the count
    count++;
}


//Implementation of shrink
void Shrink(){
    //abort operation if the count still > 30% of size
    if(count > (size*3/10)){
        return;        	    
    }
    
    //allocating a new smaller space vector
    int newSize = size*3/10;
    double *newVector;
    newVector = malloc(newSize * sizeof(double));
    
    //copying elements from the old to the new vector
    int i;
    for (i = 0; i < count; i++) {
        *(newVector + i) = *(v+i);
    }

    //free up the memory of the old vector
    free(v);
	
    //point the old vector to the new ememory space
    v = newVector;

    //print out the previous vector's size
    printf("previous capacity: %d\n", size);
    //adjust and print out the new vector's size
    size = newSize;
    printf("new capacity: %d\n", newSize);
}



int main() {
    
    //initialize the vector
    Initialize();
    
    //using a string here to make sure user enter 
    int option;
    //switch cases
    while(option != 5) {
        printf("\n\nMain menu:\n\n");
        printf("1. Print the array\n");
        printf("2. Append element at the end\n");
        printf("3. Remove last element\n");
        printf("4. Insert one element\n");
        printf("5. Exit\n\n");
        printf("Select an option: ");

        //getting user's option input
        scanf("%d", &option);
    
        //switch cases
        switch(option) {
            case 1 :
            PrintVector();
            break;            
            case 2 :
                printf("You selected \"Append element at the end\"\n");
                AddElement();
                break;
            case 3 :
                printf("You selected \"Remove last element\"\n");
                RemoveElement();
                break;
            case 4 :
                printf("You selected \"Insert one element\"\n");
                InsertElement();
                break;
            case 5 :
                printf("Exiting...\n\n\n");
                Finalize();
                break;
            default:
                printf("Invalid Option");
                while(getchar() != '\n');
                break;
        }
    }

    return 0;
}
