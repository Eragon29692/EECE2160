#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//struct CarRecord
struct CarRecord
{
    char make[20];
    char model[20];
    int year;
    char color[20];
    struct CarRecord *next;
};


//struct List
struct List
{
    // First car in the list. A value equal to NULL indicates that the
    // list is empty.
    struct CarRecord *head;
    // Current car in the list. A value equal to NULL indicates a
    // past-the-end position.
    struct CarRecord *current;
    // Pointer to the element appearing before 'current'. It can be NULL if
    // 'current' is NULL, or if 'current' is the first element in the list.
    struct CarRecord *previous;
    // Number of persons in the list
    int count;
};




// Give an initial value to all the fields in the list.
void ListInitialize(struct List *list)
{
    list->head = NULL;
    list->current = NULL;
    list->previous = NULL;
    list->count = 0;
}




// Move the current position in the list one element forward. If last element
// is exceeded, the current position is set to a special past-the-end value.
void ListNext(struct List *list)
{
    if (list->current)
    {
        list->previous = list->current;
        list->current = list->current->next;
    }
}




// Move the current position to the first element in the list.
void ListHead(struct List *list)
{
    list->previous = NULL;
    list->current = list->head;
}




// Get the element at the current position, or NULL if the current position is
// past-the-end.
struct CarRecord *ListGet(struct List *list)
{
    return list->current;
}




// Insert a car before the element at the current position in the list. If
// the current position is past-the-end, the car is inserted at the end of
// the list. The new car is made the new current element in the list.
void ListInsert(struct List *list, struct CarRecord *car)
{
    // Set 'next' pointer of current element
    car->next = list->current;
    // Set 'next' pointer of previous element. Treat the special case where
    // the current element was the head of the list.
    if (list->current == list->head)
        list->head = car;
    else
        list->previous->next = car;
    // Set the current element to the new car
    list->current = car;
}




//Print the struct
void PrintCarRecord(struct CarRecord *carRecord)
{
    printf("\tMake: %s,\tModel: %10s,\tYear: %d,\tColor: %s\n",
           carRecord->make, carRecord->model,
           carRecord->year, carRecord->color);
}




// takes the list pointer and uses print person to print each person
void print_cars_list(struct List *list)
{
    int i = 0;
    //start the current form the head pointer
    ListHead(list);
    //move curent pointer through the list and print each Person link
    while (list->current)
    {
        printf("Record %d: ", i + 1);
        //print the car record at list->current
        PrintCarRecord(ListGet(list));
        //move list current to the next record
        ListNext(list);
        i++;
    }
    //return the current pointer to the beginning
    ListHead(list);
}



//swap the position of the 2 person node
//this function is used for sorting the linked list using buble sort
void Swap(struct List *list)
{
    //make temp pointer for swaping
    struct CarRecord *temp;

    //if the current is head, then we need to mark the next as head
    //before swap the current head
    if (list->current == list->head)
    {
        list->head = list->current->next;
    }

    //current node is 1st, next of it is 2nd, and next of its next is 3rd
    //0th is the node previous to current
    //temp point to the next node (2nd node)
    temp = list->current->next;
    //point the current node 1st to the (3rd node)
    list->current->next = list->current->next->next;
    //connect the 0th node to the 2nd node
    if (list->previous)
        list->previous->next = temp;

    //point the (2nd node) to the current node 1st
    temp->next=list->current;
    //point previous pointer to the prviously 2nd node
    list->previous = temp;
}



//bubble sort the linked list
void sort_cars_by_color(struct List *list)
{
    int i;
    //place current pointer at head
    ListHead(list);
    //bubble sort
    for (i=0;i<list->count-1;i++)
    {
        while (list->current->next)
        {
            //compare the 2 colors
            if (strcmp(list->current->color, list->current->next->color)>0)
            {
                //swap
                Swap(list);
            }
            else
            {
                //if can't swap then move to the next node
                //and continute comparing
                ListNext(list);
            }
        }
        //return to the head to compare again
        ListHead(list);
    }
}


//Add a car to the linked list
void insert_linkedList(struct List *list)
{
    //freeing the old memory everytime inserting is called
    //starting with the head, then move along the list
    ListHead(list);
    ListNext(list);
    //remove the previous until reach the end
    while (list->current) {
        free(list->previous);
        ListNext(list);
    }
    //free the last one
    free(list->current);

    //initialize the new list
    ListInitialize(list);

    printf("\nInserting Records from CarRecords.txt...\n");
    FILE *fp;
    char temp[20];
    int i = 0;
    //reading from file
    fp = fopen("CarRecords.txt","r"); // read mode
    //check for openning file error
    if ( fp == NULL )
    {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }
    //inserting from file to struct one by one
    for (; i < 10; i++)
    {
        //make a new car's record
        struct CarRecord *car = (struct CarRecord *)malloc(sizeof(struct CarRecord));
        //inserting from file to varialbles
        fscanf(fp, "%s %s %s %s", car->make, car->model, temp, car->color);
        //convert year from string to integer
        car->year = atoi(strncpy(temp, temp, strlen(temp)-1));
        //remove the last ending comma in make
        car->make[strlen(car->make) - 1] = '\0';
        //remove the last ending comma in model
        car->model[strlen(car->model) - 1] = '\0';
        //set up the car pointers
        car->next = NULL;
        //insert the car
        ListInsert(list, car);
        //adjusting the count of the list
        list->count = list->count + 1;
    }
}




//print_duplicates
void print_duplicates(struct List *list)
{
    int i;
    struct CarRecord *cursor = list->head->next;
    //place current pointer at head
    ListHead(list);
    //compare the current car with the rest of the list behind
    //which cursor is being used to point to the comparing target
    for (i=0;i<list->count-1;i++)
    {
        while (cursor)
        {
            //compare the 2 cars
            if (strcmp(list->current->make, cursor->make)==0
                    && strcmp(list->current->model, cursor->model)==0
                    && list->current->year == cursor->year
                    && strcmp(list->current->color, cursor->color)==0)
            {
                //then print them both if the same
                PrintCarRecord(list->current);
                PrintCarRecord(cursor);
            }
            //check the next one
            cursor = cursor->next;
        }
        //move the current pointer
        ListNext(list);
        //move the cursor
        cursor = list->current->next;
    }
}




int main()
{
    int option;
    struct List list;				// Create the main list
    ListInitialize(&list);			// Initialize the list
    while (option != 5)
    {
        printf("\n\nMENU - Select an option:\n\n");
        printf("1. Print the cars list\n");
        printf("2. Insert car records into a sorted list\n");
        printf("3. Sort cars by color\n");
        printf("4. Print duplicates\n");
        printf("5. Exit\n\n");
        printf("Select an option: ");
        //getting user's option input
        scanf("%d", &option);
        //switch cases
        switch (option)
        {
        case 1 :
            printf("You selected \"Print the car records\"\n");
            print_cars_list(&list);
            break;
        case 2 :
            printf("You selected \"Insert the records from file\"\n");
            insert_linkedList(&list);
            break;
        case 3 :
            printf("You selected \"Sort the records by color\"\n");
            sort_cars_by_color(&list);
            break;
        case 4 :
            printf("You selected \"Print duplicated records\"\n");
            print_duplicates(&list);
            break;
        case 5 :
            printf("Exiting...\n\n\n");
            //Finalize();
            break;
        default:
            printf("Invalid Option");
            break;
        }
        printf("\nDone\n\n");
    }
    return 0;
}


