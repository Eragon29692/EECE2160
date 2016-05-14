#include <stdio.h>

int main(void)
{
	//create array a to store the numbers
	//int i, c, d for counters in the for loops
	//int swap for swapping the elememts in the sort process
    int a[10], i, d, c, swap;

	//This for loop is used to promt the user for 10 numbers
    for (i =0;i<10;i++) {
		printf("Please input a number:  ");
		scanf("%d",&a[i]);
    }

	//This nested for loop is used to bubble sort the elements of the array
    for (c = 0 ; c < (9 ); c++) {
        for (d = 0 ; d < 9 - c ; d++) {
            if (a[d] > a[d+1]) {
                swap   = a[d];
                a[d]   = a[d+1];
                a[d+1] = swap;
            } 
        }
    } 

	//This for loop is used to print the sorted array
	//Notice we only print until the one before the last element
    for (c=0;c<9;c++) {
        printf("%d, ", a[c]);
    }
	
	//print the last element of the aray seperatly to avoid the last comma
    printf("%d\n", a[c]);
	
	return 0;
}

