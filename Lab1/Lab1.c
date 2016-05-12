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
void Initialize() {
    count = 0;
    size = 2;
    v = malloc(2 * sizeof(double));
}

//Implementation of Finalize
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
	*(newVector + i) = *(v+i); 
    }

    free(v);
    v = newVector;
    printf("previous capacity: %d\n", size);
    size = size*2;
    printf("new capacity: %d\n",size);
}

//Implementation of Add Element
void AddElement(){
    float newelem;
    printf("\nEnter a new element: ");
    scanf("%f", &newelem);
    while(getchar() != '\n');
    if (count == size){
        Grow();
    }
    *(v + count) = newelem;
    count++;
}


//prints the whole vector
void PrintVector(){
    int i;
    printf("You have selected to print the array:\n ");
    for (i = 0; i < count - 1; i++){
        printf("%lf, ",*(v+i));
    }
    if (count > 0) {
     printf("%lf\n", *(v+i));
    }
}

//Implementation of remove element
void RemoveElement(){
    if (count == 0){
	printf("You can not delete a vector that is empty\n");
	return;
    }
    count  = count-1;
    Shrink();
}

//Implementation of insert element
void InsertElement(){
    int placement;
    int newelem;
    int i;
    if (count == size){
	Grow();
    }
    printf("Enter the index of the new element:");
    scanf("%d",&placement);
    while(getchar() != '\n');

    if (placement > count + 1 || placement <= 0) {
        printf("you can not add elements outside the boundaries of the array\n");
        return;
    }
   
    printf("Enter the new element:");
    scanf("%d",&newelem);
    while(getchar() != '\n');

    for (i = count - 1; i >= placement - 1; i--){
	*(v + i + 1) = *(v + i);
    }
    
    *(v + placement - 1) = newelem;

    count++;
}
//Implementation of shrink
void Shrink(){
    if(count > (size*3/10)){
        return;        	    
    }
    int newSize = size*3/10;
    double *newVector;
    newVector = malloc(newSize * sizeof(double));
    
    int i;
    for (i = 0; i < count; i++) {
        *(newVector + i) = *(v+i);
    }

    free(v);
    v = newVector;
    printf("previous capacity: %d\n", size);
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
