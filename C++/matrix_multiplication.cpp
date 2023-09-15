#include <chrono>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "helpers/CmdArguements.h"
#include "helpers/GeneralHelpers.h"

int **a; // Matrix A
int aRows; // No. rows in Matrix A
int aColumns; // No. columns in Matrix A
int **b; // Matrix B
int bRows; // No. rows in Matrix B
int bColumns; // No. columns in Matrix B
int **c; // Result Matrix C
int rs; //Result Matrix Size (Result matrix is always a square)
CmdArguments cmdArgs;

void matrixMultiply(){
    for(int y = 0; y < rs; y++){
        for(int x = 0; x < rs; x++){
            int sum = 0;
            for(int z = 0; z < aColumns; z++){
                sum += a[y][z] * b[z][x];
            }
            c[y][x] = sum;
        }
    }
}

int main(int argc, char **argv) {
    cmdArgs = getCmdArguements(argc, argv);

    int max = cmdArgs.rows;
    if(cmdArgs.cols > max){
        max = cmdArgs.cols;
    }

    /* initialize random seed: */
    // srand (time(NULL));
    srand (42);

    aRows = cmdArgs.rows;
    aColumns = cmdArgs.cols;

    bRows = cmdArgs.cols;
    bColumns = cmdArgs.rows;

    rs = aRows; //Result Size

    if(aRows != bColumns){
        printf("Cannot multiply matrixes when matrix A rows are not equal to B rows.\n");
        return -1;
    }

    printf("A - Rows: %d, Columns: %d\n", aRows, aColumns);
    printf("B - Rows: %d, Columns: %d\n", bRows, bColumns);
    printf("Result matrix C - Rows: %d, Columns: %d\n", rs, rs);
    printf("\n");

    auto t1 = std::chrono::high_resolution_clock::now();
    a = new int*[aRows];
    for(int y = 0; y < aRows; y++){
        a[y] = new int[aColumns];
        for(int x = 0; x < aColumns; x++){
            a[y][x] = rand() % max + 1;
        }
    }
    auto t2 = std::chrono::high_resolution_clock::now();
    printf("Initializing A took: %ld ms\n", std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count());

    t1 = std::chrono::high_resolution_clock::now();
    b = new int*[bRows];
    for(int y = 0; y < bRows; y++){
        b[y] = new int[bColumns];
        for(int x = 0; x < bColumns; x++){
            b[y][x] = rand() % max + 1;
        }
    }
    t2 = std::chrono::high_resolution_clock::now();
    printf("Initializing B took: %ld ms\n", std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count());

    t1 = std::chrono::high_resolution_clock::now();
    c = new int*[rs];
    for(int x = 0; x < rs; x++){
        c[x] = new int[rs];
    }
    t2 = std::chrono::high_resolution_clock::now();
    printf("Initializing C took: %ld ms\n", std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count());

    t1 = std::chrono::high_resolution_clock::now();
    matrixMultiply();
    t2 = std::chrono::high_resolution_clock::now();
    long executionTime = std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count();
    printf("The multiplication took: %ld ms\n", executionTime);

    if(cmdArgs.debugMode){
        printf("Matrix A:\n");
        printMatrix(a, aRows, aColumns);
        printf("Matrix B:\n");
        printMatrix(b, bRows, bColumns);
        printf("Result Matrix C:\n");
        printMatrix(c, rs, rs);
    }
    printf("\nCPUs,ms\n%d,%ld\n", cmdArgs.cpus, executionTime);
    printf("\n");
    return 0;
}