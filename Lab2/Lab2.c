#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//new
// Linked List Management Code
struct Person
{
	// Unique identifier for the person
	int id;
	// Information about person
	char name[20];
	int age;
	// Pointer to next person in list
	struct Person *next;
};
struct List
{
	// First person in the list. A value equal to NULL indicates that the
	// list is empty.
	struct Person *head;
	// Current person in the list. A value equal to NULL indicates a
	// past-the-end position.
	struct Person *current;
	// Pointer to the element appearing before 'current'. It can be NULL if
	// 'current' is NULL, or if 'current' is the first element in the list.
	struct Person *previous;
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
struct Person *ListGet(struct List *list)
{
	return list->current;
}
// Set the current position to the person with the given id. If no person
// exists with that id, the current position is set to past-the-end.
void ListFind(struct List *list, int id)
{
	ListHead(list);
	while (list->current && list->current->id != id)
		ListNext(list);
}
// Insert a person before the element at the current position in the list. If
// the current position is past-the-end, the person is inserted at the end of
// the list. The new person is made the new current element in the list.
void ListInsert(struct List *list, struct Person *person)
{
	// Set 'next' pointer of current element
	person->next = list->current;
	// Set 'next' pointer of previous element. Treat the special case where
	// the current element was the head of the list.
	if (list->current == list->head)
		list->head = person;
	else
		list->previous->next = person;
	// Set the current element to the new person
	list->current = person;
}
// Remove the current element in the list. The new current element will be the
// element that appeared right after the removed element.
void ListRemove(struct List *list)
{
	// Ignore if current element is past-the-end
	if (!list->current)
		return;
	// Remove element. Consider special case where the current element is
	// in the head of the list.
	if (list->current == list->head)
		list->head = list->current->next;
	else
		list->previous->next = list->current->next;
	// Free element, but save pointer to next element first.
	struct Person *next = list->current->next;
	free(list->current);
	// Set new current element
	list->current = next;
}
void PrintPerson(struct Person *person)
{
	printf("Person with ID %d:\n", person->id);
	printf("\tName: %s\n", person->name);
	printf("\tAge: %d\n\n", person->age);
}

/** main function: Will create and process a linked list
 */
int main() {
	struct List list;				// Create the main list
	ListInitialize(&list);			// Initialize the list
//*************** PUT THE REST OF YOUR CODE HERE  *****************
    
	//using a string here to make sure user enter 
    int option;
    //switch cases
    while(option != 5) {
        printf("\n\nMain menu:\n\n");
        printf("1. Add a person\n");
        printf("2. Find a person\n");
        printf("3. Remove a person\n");
        printf("4. Print the list\n");
        printf("5. Exit\n\n");
        printf("Select an option: ");

        //getting user's option input
        scanf("%d", &option);
    
        //switch cases
        switch(option) {
            case 1 :
                printf("You selected \"Add a person\"\n");
                break;            
            case 2 :
                printf("You selected \"Find a person\"\n");
                //AddElement();
                break;
            case 3 :
                printf("You selected \"Remove a person\"\n");
                //RemoveElement();
                break;
            case 4 :
                printf("You selected \"Print the list\"\n");
                //InsertElement();
                break;
            case 5 :
                printf("Exiting...\n\n\n");
                //Finalize();
                break;
            default:
                printf("Invalid Option");
                while(getchar() != '\n');
                break;
        }
    }

	return 0;
} //end main
