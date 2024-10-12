/*Hannah Prosch 
EECS 148 Lab5
Programming Problem #2:
Matrix Manipulation
October 11, 2024*/

#include <stdio.h>
//Used to create the size of our arrays/matrices:
#define SIZE 5

void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE]);
void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE]);
void transposeMatrix(int m3[SIZE][SIZE]);
void printMatrix(int matrix[SIZE][SIZE]);

int main()
{
    /*Declare and initialize the 2-d arrays/matrices*/
    int m1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };
    
    addMatrices(m1, m2);
    /*Error handling for invalid matrix operations 
    (incompatible dimensions for multiplication):*/
    int cols = sizeof(m1[0]) / sizeof(m1[0][0]);
    int rows = sizeof(m2) / sizeof(m2[0]);
    if (rows == cols) {
        multiplyMatrices(m1, m2);
    } else {
        printf("Sorry, the number of columns in the first matrix must match the number of rows in the second matrix to multiply them.");
    }
    transposeMatrix(m1);
    transposeMatrix(m2);
}

void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE]) {
        /*Declare and create a new array to store calculated values:*/
        int matrix[SIZE][SIZE];
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                matrix[i][j] = 0;
            }
        }

        /*Add the matrices together, and put the
        sum into the matrix double array:*/
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                matrix[i][j] = m1[i][j] + m2[i][j];
            }
        }
        printf("\nAdded Matrices:\n");
        printMatrix(matrix);
}

void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE]) {
        /*Declare and create a new array to store calculated values:*/
        int matrix[SIZE][SIZE];
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                matrix[i][j] = 0;
            }
        }

        /*Multiply the matrices together, and put the
        product into the matrix double array:*/
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int h = 0; h < SIZE; h++) {
                    matrix[i][j] = matrix[i][j] + (m1[i][h] * m2[h][j]);
                }
                
            }
        }
        printf("\nMultiplied Matrices:\n");
        printMatrix(matrix);
}

void transposeMatrix(int m3[SIZE][SIZE]) {
    /*Declare and create a new array to store transposed values:*/
    int matrix[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] = m3[j][i];
        }
    }
    printf("\nTransposed Matrix:\n");
    printMatrix(matrix);
}

void printMatrix(int matrix[SIZE][SIZE]) {
    int counter = 0;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%i\t", matrix[i][j]);
            counter++;
            /*Starts a new line once we've printed
            an entire row to the console:*/
            if (counter % SIZE == 0) {
                printf("\n");
            }
        }
    }
}