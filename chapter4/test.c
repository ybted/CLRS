#include <stdio.h>
#include <limits.h>
#include <malloc.h>
#include "FIND-MAXIMUM-SUBARRAY.c"
#include "Strassen_method.c"
int main()
{
    int a[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    int* ans = find_maximum_subarray(a, 0, 15);
    printf("max sum: %d", ans[2]);
    printf("\n");
    int b[][3] = {{1, 2, 3} , {4, 5, 6}, {7, 8, 9}};
    int c[][3] = {{1, 9, 2} , {8, 3, 7}, {4, 6, 5}};
    int *p[3];
    p[0] = b[0];
    p[1] = b[1];
    p[2] = b[2];
    int *q[3];
    q[0] = c[0];
    q[1] = c[1];
    q[2] = c[2];
    int** m = square_matrix_mutiply(p, q, 3);

    for (int i = 0; i < 3; i ++)
    {
        for (int j = 0; j < 3; j ++)    
            printf("%d ", m[i][j]);
        printf("\n");
    }
    printf("\n");

    int** A = init_matrix(2);
    int** B = init_matrix(2);
    A[0][0]=1;
    A[0][1]=3;
    A[1][0]=7;
    A[1][1]=5;

    B[0][0]=6;
    B[0][1]=8;
    B[1][0]=4;
    B[1][1]=2;
    int** C = square_matrix_mutiply_recursive(A, B, 2);
    print_matrix(C, 2, 2);

    int** D = Strassen_method(A, B, 2);
    print_matrix(D, 2, 2);

}