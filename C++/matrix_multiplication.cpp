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

    int bRows = cmdArgs.cols;
    int bColumns = cmdArgs.rows;

    int rs = aRows; //Result Size

    if(aRows != bColumns){
        printf("Cannot multiply matrixes when matrix A rows are not equal to B rows.\n");
        return -1;
    }

    printf("A - Rows: %d, Columns: %d\n", aRows, aColumns);
    printf("B - Rows: %d, Columns: %d\n", bRows, bColumns);
    printf("Result matrix C - Rows: %d, Columns: %d\n", rs, rs);
    printf("\n");

    int **a = new int*[aRows];
    for(int y = 0; y < aRows; y++){
        a[y] = new int[aColumns];
        for(int x = 0; x < aColumns; x++){
            a[y][x] = rand() % max + 1;
        }
    }
    
    int **b = new int*[bRows];
    for(int y = 0; y < bRows; y++){
        b[y] = new int[bColumns];
        for(int x = 0; x < bColumns; x++){
            b[y][x] = rand() % max + 1;
        }
    }

    if(cmdArgs.debugMode){
        printf("Matrix A:\n");
        printMatrix(a, aRows, aColumns);
        printf("Matrix B:\n");
        printMatrix(b, bRows, bColumns);
    }

    int **c = new int*[rs];
    for(int x = 0; x < rs; x++){
        c[x] = new int[rs];
    }

    for(int y = 0; y < rs; y++){
        for(int x = 0; x < rs; x++){
            int sum = 0;
            for(int z = 0; z < aColumns; z++){
                sum += a[y][z] * b[z][x];
            }
            c[y][x] = sum;
        }
    }

    if(cmdArgs.debugMode){
        printf("Result matrix (C):\n");
        printMatrix(c, rs, rs);
    }
    printf("\n");
    return 0;
}