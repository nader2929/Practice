#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main() {
    int a[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    int b[3][2] = {
        {7, 8},
        {9, 10},
        {11, 12}
    };

    int aRows = sizeof(a) / sizeof(a[0]);
    int aColumns = sizeof(a[0]) / sizeof(a[0][0]);

    int bRows = sizeof(b) / sizeof(b[0]);
    int bColumns = sizeof(b[0]) / sizeof(b[0][0]);

    printf("A - Rows: %d, Columns: %d\n", aRows, aColumns);
    printf("B - Rows: %d, Columns: %d\n", bRows, bColumns);

    if(aRows != bColumns){
        printf("Cannot multiply matrixes when matrix A rows are not equal to B rows.\n");
        return 0;
    }

    int rs = aRows; //Result Size
    int c[rs][rs];

    for(int x = 0; x < rs; x++){
        for(int y = 0; y < rs; y++){
            int sum = 0;
            for(int z = 0; z < aColumns; z++){
                printf("\t Adding A[%d][%d] and B[%d][%d]\n", x, z, z, y);
                sum += a[x][z] * b[z][y];
            }
            c[x][y] = sum;
            printf("C[%d][%d]: %d\n", x, y, sum);
        }
    }

    printf("\n");
    return 0;
}