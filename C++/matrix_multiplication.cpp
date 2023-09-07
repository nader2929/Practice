#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "helpers/CmdArguements.h"

void printMatrix(int **matrix, int rows, int cols){
    for(int x = 0; x < rows; x++){
        for(int y = 0; y < cols; y++){
            if(y == 0){
                printf(" %d,%d - ", x, y);
                printf("%d |", matrix[x][y]);
            }
            else if(y == cols-1){
                printf(" %d,%d -", x, y);
                printf(" %d", matrix[x][y]);
            }
            else{
                printf(" %d,%d - ", x, y);
                printf(" %d |", matrix[x][y]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main(int argc, char **argv) {
    CmdArguments cmdArgs = getCmdArguements(argc, argv);

    int max = cmdArgs.rows;
    if(cmdArgs.cols > max){
        max = cmdArgs.cols;
    }

    /* initialize random seed: */
    srand (time(NULL));

    int aRows = cmdArgs.rows;
    int aColumns = cmdArgs.cols;

    int **a = new int*[aRows];
    for(int x = 0; x < aColumns; x++){
        a[x] = new int[aColumns];
        for(int y = 0; y < aColumns; y++){
            a[x][y] = rand() % max + 1;
        }
    }

    int bRows = cmdArgs.cols;
    int bColumns = cmdArgs.rows;
    
    int **b = new int*[bRows];
    for(int x = 0; x < bRows; x++){
        b[x] = new int[bColumns];
        for(int y = 0; y < bColumns; y++){
            b[x][y] = rand() % max + 1;
        }
    }

    printf("A - Rows: %d, Columns: %d\n", aRows, aColumns);
    printMatrix(a, aRows, aColumns);
    printf("B - Rows: %d, Columns: %d\n", bRows, bColumns);
    printMatrix(b, bRows, bColumns);

    if(aRows != bColumns){
        printf("Cannot multiply matrixes when matrix A rows are not equal to B rows.\n");
        return 0;
    }

    int rs = aRows; //Result Size
    int **c = new int*[rs];
    for(int x = 0; x < rs; x++){
        c[x] = new int[rs];
    }

    for(int x = 0; x < rs; x++){
        for(int y = 0; y < rs; y++){
            int sum = 0;
            for(int z = 0; z < aColumns; z++){
                sum += a[x][z] * b[z][y];
            }
            c[x][y] = sum;
        }
    }

    printf("Result matrix (C):\n");
    printMatrix(c, rs, rs);
    printf("\n");
    return 0;
}