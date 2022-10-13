#include "SQUARE-MATRIX-MUTIPLY.c"

int** Strassen_method(int** a, int** b, int n)
{
    int** c = init_matrix(n);
    if (n == 1) 
    {
        c[0][0] = a[0][0] * b[0][0];
    }
    else 
    {
        int k = n / 2;
        // initialize the submatrix
        int** A11 = init_matrix(k);
        int** A12 = init_matrix(k);
        int** A21 = init_matrix(k);
        int** A22 = init_matrix(k);
        int** B11 = init_matrix(k);
        int** B12 = init_matrix(k);
        int** B21 = init_matrix(k);
        int** B22 = init_matrix(k);
        for (int i = 0; i < k; i ++)
            for (int j = 0; j < k; j ++)
            {
                A11[i][j] = a[i][j];
                A12[i][j] = a[i][j+k];
                A21[i][j] = a[i+k][j];
                A22[i][j] = a[i+k][j+k];
                B11[i][j] = b[i][j];
                B12[i][j] = b[i][j+k];
                B21[i][j] = b[i+k][j];
                B22[i][j] = b[i+k][j+k];
            }
        
        int** s[10];
        for (int i = 0; i < 10; i ++)
            s[i] = init_matrix(k);
        s[0] = sub_matrix(B12, B22, k);
        s[1] = add_matrix(A11, A12, k);
        s[2] = add_matrix(A21, A22, k);
        s[3] = sub_matrix(B21, B11, k);
        s[4] = add_matrix(A11, A22, k);
        s[5] = add_matrix(B11, B22, k);
        s[6] = sub_matrix(A12, A22, k);
        s[7] = add_matrix(B21, B22, k);
        s[8] = sub_matrix(A11, A21, k);
        s[9] = add_matrix(B11, B12, k);

        int** p[7];
        for (int i = 0; i < 7; i ++)
            p[i] = init_matrix(k);
        
        p[0] = Strassen_method(A11, s[0], k);
        p[1] = Strassen_method(s[1], B22, k);
        p[2] = Strassen_method(s[2], B11, k);
        p[3] = Strassen_method(A22, s[3], k);
        p[4] = Strassen_method(s[4], s[5], k);
        p[5] = Strassen_method(s[6], s[7], k);
        p[6] = Strassen_method(s[8], s[9], k);

        int** C11 = sub_matrix(add_matrix(add_matrix(p[4], p[3], k), p[5], k), p[1], k);
        int** C12 = add_matrix(p[0], p[1], k);
        int** C21 = add_matrix(p[2], p[3], k);
        int** C22 = sub_matrix(add_matrix(p[4], p[0], k), add_matrix(p[2], p[6], k), k);

        for (int i = 0; i < k; i ++)
            for (int j = 0; j < k; j ++)
            {
                c[i][j] = C11[i][j];
                c[i][j+k] = C12[i][j];
                c[i+k][j] = C21[i][j];
                c[i+k][j+k] = C22[i][j];
            }

    }
    return c;
}