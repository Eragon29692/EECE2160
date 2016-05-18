#include <stdio.h>
#include <stdlib.h>

/*
* This program is done in simple way since
* this matrix is an even 3 x 3 matrix
* Therefore using this for Ex 2 x 3 matrices will need changes in code
*/

//size of the matrix
int matrixSize = 9;
//each side of matrix
int matrixSide = 3;

//print out the matrix
void printMatrix(int *matrix) {
    int i;
    printf("The matrix is: \n\t");
    //the idea is:
    //from the 1 dimentinal array that represent the matrix
    //if the index of that number is divisible by 3 (which is the matrix size)
    for (i = 0; i < matrixSize; i++) {
        if (i % 3 == 0 && i != 0) {
            printf("\n\t");
        }
        printf("%d\t", *(matrix + i));
    }

    //print newlines for readability
    printf("\n\n");
}

//transpose the matrix using array index
void indexTranspose(int matrix[matrixSize]) {
    int i;
    //the idea is to calculate the index of the element to swap
    //by calculate the element index into row and column
    //the index normally is: index = column + row * matrixSide
    //But we trnasposing it by switching it to row + column * matrixSide
    for (i = 0; i < matrixSize; i++) {
        int row = i / matrixSide;
        int column = i % matrixSide;
        int index = row + column * matrixSide;
        //since we goes through the whole list

        //This if below make sure swapping once for each pair of indexcies
        if (index > i) {
            int temp = matrix[i];
            matrix[i] = matrix[index];
            matrix[index] = temp;
        }
    }

}

//transpose the matrix using pointer
void pointerTranspose(int *matrix) {
    int i;
    //the idea is to calculate the index of the element to swap
    //by calculate the element index into row and column
    //the index normally is: index = column + row * matrixSide
    //But we trnasposing it by switching it to row + column * matrixSide
    for (i = 0; i < matrixSize; i++) {
        int row = i / matrixSide;
        int column = i % matrixSide;
        int index = row + column * matrixSide;
        //since we goes through the whole list
        //This if below make sure swapping once for each pair of indexcies
        //This is the only part
        //where it is different from transpose by index above
        if (index > i) {
            int temp = *(matrix + i);
            *(matrix + i) = *(matrix + index);
            *(matrix + index) = temp;
        }
    }

}



//main
int main(void) {
    int *matrix = malloc(sizeof(int) * matrixSize);
    int i;


    //prompt for user input
    for (i =0;i < matrixSize;i++) {
        printf("Please input a number:  ");
        scanf("%d", matrix + i);
    }

    //print the matrix
    printMatrix(matrix);

    //index transpose
    printf("a) Transpose using indexces\n");
    indexTranspose(matrix);
    printMatrix(matrix);

    //pointer transpose
    printf("b) Transpose using pointer\n");
    pointerTranspose(matrix);
    printMatrix(matrix);

}

