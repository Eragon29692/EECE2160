#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

struct CarRecord
{
    char make[20];
    char model[20];
    int year;
    char color[20];
};

void insert_array( struct CarRecord carRecords[10] ) {
    printf("\nInserting Records from CarRecords.txt...\n");
    FILE *fp;
    char buffer;
    char temp[20];
    int i = 0;
    int k = 0;
    fp = fopen("CarRecords.txt","r"); // read mode
    if ( fp == NULL )
    {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }

    while ((buffer = fgetc(fp)) != EOF) {
        k = 0;
        while (buffer != ',') {
            carRecords[i].make[k] = buffer;
            buffer = fgetc(fp);
	    k++;
        }
	carRecords[i].make[k] = '\0';
	
        buffer = fgetc(fp);
        buffer = fgetc(fp);
	k = 0;
        while (buffer != ',') {
            carRecords[i].model[k] = buffer;
            buffer = fgetc(fp);
	    k++;
        }
        carRecords[i].model[k] = '\0';

        buffer = fgetc(fp);
        fscanf(fp, "%d", &carRecords[i].year);

	buffer = fgetc(fp);
	buffer = fgetc(fp);
        buffer = fgetc(fp);
	k = 0;
        while ( buffer != '\n' && buffer != EOF) {
            carRecords[i].color[k] = buffer;
            buffer = fgetc(fp);
	    k++;
        }
	carRecords[i].color[k] = '\0';

	if (buffer == EOF) 
	    break;

        i++;
    }
    printf("\nFinished\n");
}

void print_cars_array( struct CarRecord carRecords[10]) {
    int i;
    printf("\nPrinting car records:\n");
    for (i = 0; i < 10; i++) {
        printf("\nRecord %d:\n\tMake: %s,\n\tModel: %s,\n\tYear: %d,\n\tColor: %s\n",
               i + 1, carRecords[i].make, carRecords[i].model, carRecords[i].year, carRecords[i].color);
    }
}

int main()
{
    int option;
    struct CarRecord carRecords[10];
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
            print_cars_array(carRecords);
            break;
        case 2 :
            printf("You selected \"Insert the records from file\"\n");
            insert_array(carRecords);
            break;
        case 3 :
            printf("You selected \"Sort the records by year\"\n");
            //RemovePerson(&list);
            break;
        case 4 :
            printf("You selected \"Print duplicated records\"\n");
            //PrintList(&list);
            break;
        case 5 :
            printf("Exiting...\n\n\n");
            //Finalize();
            break;
        default:
            printf("Invalid Option");
            break;
        }
    }
    return 0;
}
