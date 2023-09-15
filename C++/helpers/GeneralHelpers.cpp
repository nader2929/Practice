#include <iostream>


void printMatrix(int **matrix, int rows, int cols){
    for(int y = 0; y < rows; y++){
        for(int x = 0; x < cols; x++){
            if(x == 0){
                printf(" %d,%d - ", y, x);
                printf("%d |", matrix[y][x]);
            }
            else if(x == cols-1){
                printf(" %d,%d -", y, x);
                printf(" %d", matrix[y][x]);
            }
            else{
                printf(" %d,%d - ", y, x);
                printf(" %d |", matrix[y][x]);
            }
        }
        printf("\n");
    }
    printf("\n");
}