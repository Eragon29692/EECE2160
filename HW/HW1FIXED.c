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
    fp = fopen("CarRecords.txt","r"); // read mode
    if ( fp == NULL )
    {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }

    while (fscanf(fp, "%s %s %s %s", carRecords[i].make, carRecords[i].model, temp, carRecords[i].color)
            != EOF) {
        carRecords[i].year = atoi(strncpy(temp, temp, strlen(temp)-1));
	carRecords[i].make[strlen(carRecords[i].make) - 1] = '\0';
        carRecords[i].model[strlen(carRecords[i].model) - 1] = '\0';
        i++;
    }
}

void print_cars_array( struct CarRecord carRecords[10] ) {
    int i;
    printf("\nPrinting car records:\n");
    for (i = 0; i < 10; i++) {
        printf("\nRecord %d:\n\tMake: %s,\n\tModel: %s,\n\tYear: %d,\n\tColor: %s\n",
               i + 1, carRecords[i].make, carRecords[i].model, carRecords[i].year, carRecords[i].color);
    }
}

void sort_cars_by_year( struct CarRecord carRecords[10] ) {
    int i, j;
    for (i = 0; i < 10; i++) {
        for (j = 1; j < 10 - i; j++) {
            if (carRecords[j - 1].year > carRecords[j].year) {
                struct CarRecord temp = carRecords[j];
                carRecords[j] = carRecords[j - 1];
                carRecords[j - 1] = temp;
            }
        }
    }
}

void print_duplicates( struct CarRecord carRecords[10] ) {
    int i, j;
    for (i = 0; i < 10; i++) {
        for (j = i + 1; j < 10; j++) {
            if (strcmp(carRecords[i].make, carRecords[j].make) == 0
                    && strcmp(carRecords[i].model, carRecords[j].model) == 0
                    && carRecords[i].year == carRecords[j].year
                    && strcmp(carRecords[i].color, carRecords[j].color) == 0) {
						
                printf("\nRecord %d:\n\tMake: %s,\n\tModel: %s,\n\tYear: %d,\n\tColor: %s\n",
                       i + 1, carRecords[i].make, carRecords[i].model, carRecords[i].year, carRecords[i].color);
                printf("\nRecord %d:\n\tMake: %s,\n\tModel: %s,\n\tYear: %d,\n\tColor: %s\n",
                       j + 1, carRecords[j].make, carRecords[j].model, carRecords[j].year, carRecords[j].color);
		printf("-----------------------------------");
            }
        }
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
            sort_cars_by_year(carRecords);
            break;
        case 4 :
            printf("You selected \"Print duplicated records\"\n");
            print_duplicates(carRecords);
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

