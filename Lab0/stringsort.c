#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    //create a 2 dimentinal array to store 10 strings
    char str[10][20];
	//a temp string for swapping in the sort process
    char temp[20];
	//int i and j are used for counters in the for loops
    int i, j;

	//promt user for 10 strings and store them in the 2 dimentinal array
    for (i = 0; i < 10; i++) {
        printf("Enter the name %d: ", i);
        fgets(str[i], 20, stdin);
	str[i][strlen(str[i]) - 1] = '\0';
    }

	//sort the strings in the 2 dimentinal array using strcmp and strcpy
    for (i = 0; i < 10; i++) {
       for (j = 0; j < 9; j++) {
          if (strcmp(str[j], str[j + 1]) > 0) {
             strcpy(temp, str[j]);
             strcpy(str[j], str[j + 1]);
             strcpy(str[j + 1], temp);
          }
       }
    }

    //print the sorted list of strings
    printf("\nSorted List : ");
    for (i = 0; i < 9; i++){
        printf("%s, ",str[i]);
    }
	//print the last element of the array seperatly to avoid the ending comma
    printf("%s\n",str[9]);
	
    return (0);
}
