#include <stdio.h>
#include <stdlib.h>

//Global variable for the vector
double *v;
int count;
int size;

//initialize the vector
void Initialize();
void Finalize();

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
		printf("You selected \"Print the array\"");
		break;            
	    case 2 :
                printf("You selected \"Append element at the end\"");
                break;
            case 3 :
                printf("You selected \"Remove last element\"");
                break;
            case 4 :
                printf("You selected \"Insert one element\"");
                break;
            case 5 :
                printf("Exiting...\n");
		Finalize();
                break;
	    default:
		printf("Invalid Option");

	}		
    }
    
    return 0;
}



