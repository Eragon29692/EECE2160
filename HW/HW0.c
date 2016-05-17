#include <stdio.h>

int add(int x, int y);
int difference(int x, int y);
void printBinary(int x);


int add(int x, int y) {
    while (y != 0) {
        int carry = x & y;
        x = x ^ y;
        y = carry << 1;
    }
    return x;
}

int difference(int x, int y) {
    if (add(x, add(~y, 1)) > 0)
        return add(x, add(~y, 1));
    else 
        return add(y, add(~x, 1)); 
}

void printBinary(int x) {
    int i;
    int size = 2<<sizeof(int);
    for (i = size; i > 0;) {
        i--;
	int num = x>>i;
        if (num & 1)
            printf("1");
        else
            printf("0");
    }   
}

int main() {
    int x, y, sum, diff;
   
    printf("Enter x: ");
    scanf("%d",&x);
    printf("Enter y: ");
    scanf("%d", &y);
    
    sum = add(x, y);
    diff = difference(x, y);

    printf("a) The result of %d + %d is: \nBase 10: %d\nBase 2: ", x, y, sum); 
    printBinary(sum);

    printf("\nb) The difference between %d and %d is: \nBase 10: %d\nBase 2: ", x, y, diff);
    printBinary(diff);

    printf("\n\n");
    return 0;
}


