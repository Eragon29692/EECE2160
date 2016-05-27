#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct CarRecord
{
    char make[20];
    char model[20];
    int year;
    char color[20];
};
struct List
{
    // First person in the list. A value equal to NULL indicates that the
    // list is empty.
    struct CarRecord *head;
    // Current person in the list. A value equal to NULL indicates a
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
// Insert a person before the element at the current position in the list. If
// the current position is past-the-end, the person is inserted at the end of
// the list. The new person is made the new current element in the list.
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
    // Set the current element to the new person
    list->current = car;
}
//Print the person struct
void PrintCarRecord(struct CarRecord *car)
{
    printf("\n\tMake: %s,\n\tModel: %s,\n\tYear: %d,\n\tColor: %s\n",
           carRecords->make, carRecords->model, carRecords->year, carRecords->color);
}
// takes the list pointer and uses print person to print each person
void print_cars_list(struct List *list)
{
    int i = 0;
    //start the current form the head pointer
    ListHead(list);
    //move curent pointer through the list and print each Person link
    while (list->current) {
        printf("\nRecord %d: ", i + 1);
        PrintCarRecord(ListGet(list));
        ListNext(list);
        i++;
    }
    //return the current pointer to the beginning
    ListHead(list);
}
//swap the position of the 2 person node
//this function is used for sorting the linked list using buble sort
void Swap(struct List *list) {
    //make temp pointer for swaping
    struct CarRecord *temp;
    //if the current is head, then we need to mark the next as head
    //before swap the current head
    if (list->current == list->head) {
        list->head=list->current->next;
    }
    //current node is 1st, next of it is 2nd, and next of its next is 3rd
    //temp point to the next node (2nd node)
    temp = list->current->next;
    //point the current node to the (3rd node)
    list->current->next = list->current->next->next;
    //point the (2nd node) to the current node
    temp->next=list->current;
}
//bubble sort the linked list
void sort_cars_by_color(struct List *list) {
    int i,j,k;
    //place current pointer at head
    ListHead(list);
    //bubble sort
    for (j=0;j<list->count-2;j++)
    {
        for (k=0;k<list->count-j-2;k++)
        {
            //sort by name
            if (strcmp(list->current->color, list->current->next->color)>0)
            {
                Swap(list);
            }
        }
    }
}
//Add a person the the linked list
void insert_linkedList(struct List *list) {
    printf("\nInserting Records from CarRecords.txt...\n");
    FILE *fp;
    char buffer;
    char temp[20];
    int i = 0;
    fp = fopen("CarRecords.txt","r"); // read mode
    if ( fp == NULL )
    {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }
    for (; i < 10; i++) {
        CarRecord *car = (CarRecord *)malloc(sizeof(CarRecord));
        fscanf(fp, "%s %s %s %s", car->make, car->model, temp, car->color);
        car->year = atoi(strncpy(temp, temp, strlen(temp)-1));
        car->make[strlen(car->make) - 1] = '\0';
        car->model[strlen(car->model) - 1] = '\0';
        car->next = NULL;
        //insert the car
        ListInsert(list, car);
        //adjusting the count of the list
        list->count = list->count + 1;
    }
}
int main()
{
    int option;
    struct List list;				// Create the main list
    ListInitialize(&list);			// Initialize the list
    while (option != 5) {
        printf("\n\nMENU - Select an option:\n\n");
        printf("1. Print the cars array\n");
        printf("2. Insert car records into a sorted array\n");
        printf("3. Sort cars by year\n");
        printf("4. Print duplicates\n");
        printf("5. Exit\n\n");
        printf("Select an option: ");
        //getting user's option input
        scanf("%d", &option);
        //switch cases
        switch (option) {
        case 1 :
            printf("You selected \"Print the car records\"\n");
            print_cars_list(carRecords);
            break;
        case 2 :
            printf("You selected \"Insert the records from file\"\n");
            insert_linkedList(carRecords);
            break;
        case 3 :
            printf("You selected \"Sort the records by year\"\n");
            sort_cars_by_color(carRecords);
            break;
        case 4 :
            printf("You selected \"Print duplicated records\"\n");
            //print_duplicates(carRecords);
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