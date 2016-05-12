/**
 * @file   TVShows.c
 * @Author Your name (email here)
 * @date   May, 2016
 * @brief  C Data structures exercise.
 *
 * This program illustrates how to operate C struct data types 
 * and linked lists
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Array struct node
struct TV_Array {          // array node
	char programName[20];  // name
	int minutes;           // Running minutes
};
typedef struct TV_Array TV_Shows; // rename the struct data type

// Linked list struct node
typedef struct TV_LinkedList { //Linked list node
    char programName[20];       // name
    int minutes;                // Running minutes
    struct TV_LinkedList *next; // pointer to next node
}TV_List; // Note the different ways of using typedef keyword

// Function prototypes
void readShows(char *tvName, int *minutes);
void Add_ShowsArray(TV_Shows *shows);
void print_ShowsArray(TV_Shows show_Info[]);
void add_LinkedList(TV_List **head);
void print_LinkedList(TV_List *head);
/**
 * Main function processes the array and linked list
 * 
 * @return 0   indicator that program was successful
 */
int main () {
	// uncomment the lines below as you progess
    TV_Shows shows[5]; // Declare an array of 5 elements
    TV_List *head = NULL; // Declare a linked list head pointer

    printf("\nProcessing Array Data....\n");
    Add_ShowsArray(shows);   // Passing an array in C means 
    print_ShowsArray(shows); //passing the pointer to the first element

    printf("\n\nProcessing Linked List Data....\n");
    //add_LinkedList(&head);  // Passing by reference
    //print_LinkedList(head); // Passing by value
    return 0;
} //end main


/**
 * Reads TV shows information from the user
 * 
 * @param tvName    pointer to the program name.
 * @param minutes   pointer to the mintes data.
 */
void readShows(char *tvName, int *minutes) {
        printf("Enter the name of the TV Program: \n");
        scanf("%s",tvName);
        printf("Enter the running time in minutes: \n");
        scanf("%d",minutes);
} //end readShows()

/** 
 * Creates the TV shows array using the readShows() function
 * 
 * @param shows   pointer to the shows array
 */
//*********DEFINE Add_ShowsArray() HERE. SEE PROTOTYPE ABOVE ********

void Add_ShowsArray(TV_Shows *shows){
	int i;
	for(i=0;i<=4;i++){
	readShows(shows[i].programName,&shows[i].minutes);
	}
}
/**
 * Prints TV shows information from array
 * 
 * @param show_Info   pointer to the shows array
 */
//*********DEFINE print_ShowsArray() HERE. SEE PROTOTYPE ABOVE ********
void print_ShowsArray(TV_Shows *shows){
	int i;
	for (i=0;i<=4;i++){
		printf("TV Show %d   " 
		printf("%s",shows[i].programName);
		printf("%d",shows[i].minutes);
	}


}









// end print_ShowsArray()

/**
 * Creates the TV shows linked list readShows() funtion
 * 
 * @param *head   pointer (TV_List **head) to the head pointer
 */
//*********DEFINE add_LinkedList() HERE. SEE PROTOTYPE ABOVE ********









 // end add_LinkedList()

/**
 * Prints TV shows information from linked List
 * 
 * @param head   head pointer to the linked list
 */
//*********DEFINE print_LinkedList() HERE. SEE PROTOTYPE ABOVE ********









 // print_LinkedList()
