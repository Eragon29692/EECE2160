#include <stdio.h>
#include <stdlib.h>

int matrixSize = 9;
int matrixSide = 3;

void printMatrix(int *matrix) {
    int i;
    printf("The matrix is: \n\t");

    for (i = 0; i < matrixSize; i++) {
	if (i % 3 == 0 && i != 0) {
            printf("\n\t");
	}
        printf("%d\t", *(matrix + i)); 
    }
    printf("\n\n");
}


void indexTranspose(int matrix[matrixSize]) {
    int i;
    
    for (i = 0; i < matrixSize; i++) {
	int row = i / matrixSide;
        int column = i % matrixSide;
        int index = row + column * matrixSide;
	
        if (index > i) {
	    int temp = matrix[i];
	    matrix[i] = matrix[index];
	    matrix[index] = temp; 
	}
    }

}


void pointerTranspose(int *matrix) {
    int i;

    for (i = 0; i < matrixSize; i++) {
        int row = i / matrixSide;
        int column = i % matrixSide;
        int index = row + column * matrixSide;

        if (index > i) {
            int temp = *(matrix + i);
            *(matrix + i) = *(matrix + index);
            *(matrix + index) = temp;
        }
    }

}


int main(void) {
    int *matrix = malloc(sizeof(int) * matrixSize);
    int i;

    for (i =0;i < matrixSize;i++) {
        printf("Please input a number:  ");
        scanf("%d", matrix + i);
    }
    
    printMatrix(matrix);
   
    printf("a) Transpose using indexces\n");
    indexTranspose(matrix);
    printMatrix(matrix); 

    printf("b) Transpose using pointer\n");
    pointerTranspose(matrix);
    printMatrix(matrix);

}
