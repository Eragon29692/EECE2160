#include <stdio.h>

//function prototypes
int add(int x, int y);
int difference(int x, int y);
void printBinary(int x);

//adding 2 numbers
int add(int x, int y) {
    //if y is not 0
    while (y != 0) {
        //carry contains the bits
        //where the add operation need to carry to the more significant bit
        //Ex: where 1 + 1
        int carry = x & y;
        //x will then be the sum x + y
        //But no carried bits has been added yet
        x = x ^ y;
        //y will then be shift left then re-added to x in the next loop
        //this is similar to normal plus operation
        //where carried bits are added to the left bit next to it
        y = carry << 1;
    }
    return x;
}

//calculate the differece between x and y
int difference(int x, int y) {
    //the difference is |x - y|
    //where it is either x + (-y) or y + (-x)
    //whichever greater than 0
    //subtraction x - y here is done by adding 1 to the flipped y (NOT y)
    if (add(x, add(~y, 1)) > 0)
        return add(x, add(~y, 1));
    else
        return add(y, add(~x, 1));
}

//print the number in binary format
void printBinary(int x) {
    int i;
    //The size in bit of int is calculated by
    //2^sizeof(int) => 2^4 = 32
    int size = 2<<sizeof(int);
    //printing out the numbers
    for (i = size; i > 0;) {
        //starting from 31
        i--;
        //num is x but right shift i numbers
        //this help doing AND operation between x and 1
        //starting form the left most bit
        int num = x>>i;
        if (num & 1)
            printf("1");
        else
            printf("0");
    }
}

//main
int main() {
    int x, y, sum, diff;
    //prompt for x and y
    printf("Enter x: ");
    scanf("%d",&x);
    printf("Enter y: ");
    scanf("%d", &y);

    //calculate sum and difference
    sum = add(x, y);
    diff = difference(x, y);

    //print out sum
    printf("a) The result of %d + %d is: \nBase 10: %d\nBase 2: ", x, y, sum);
    printBinary(sum);

    //print out difference
    printf("\nb) The difference between %d and %d is: \nBase 10: %d\nBase 2: ", x, y, diff);
    printBinary(diff);

    //format print for readability
    printf("\n\n");
    return 0;
}



