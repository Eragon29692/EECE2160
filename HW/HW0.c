#include <stdio.h>

int add(int x, int y);
void printBinary(int x);

int add(int x, int y) {
    while (y != 0) {
        int carry = x & y;
        x = x ^ y;
        y = carry << 1;
    }
    return x;
}

void printBinary(int x) {
    int i = 31;
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
    int x, y, sum;
    printf("Enter x: ");
    scanf("%d",&x);
    printf("Enter y: ");
    scanf("%d", &y);
    
    sum = add(x, y);

    printf("a) The result of %d + %d is: \nBase 10: %d\nBase 2: ", x, y, sum); 
    printBinary(sum);
    printf("\n\n");
    return 0;
}


