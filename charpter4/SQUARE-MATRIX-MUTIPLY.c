int** square_matrix_mutiply(int** a, int** b, int n)
{
    int **c = (int **) malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i ++)
        c[i] = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++)
        {
            c[i][j] = 0;
            for (int k = 0; k < n; k ++)
                c[i][j] += a[i][k] * b[k][j];
        }
    return c;
}

int** init_matrix(int n)
{
    int** a = (int**) malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i ++)
        a[i] = (int*) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++)
            a[i][j] = 0;
    return a;
}

int** add_matrix(int** a, int** b, int n)
{
    int** c = init_matrix(n);
    for (int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++) 
            c[i][j] = a[i][j] + b[i][j];
    return c;
}

int** sub_matrix(int** a, int** b, int n)
{
    int** c= init_matrix(n);
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++)    
            c[i][j] = a[i][j] - b[i][j];
    return c;
}

int** square_matrix_mutiply_recursive(int** a, int** b, int n)
{
    int** c = init_matrix(n);
    if (n == 1)
    {
        c[0][0] = a[0][0] * b[0][0];
    }
    else {
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
        int** C11 =  add_matrix(square_matrix_mutiply_recursive(A11, B11, k) , square_matrix_mutiply_recursive(A12, B21, k), k);
        int** C12 =  add_matrix(square_matrix_mutiply_recursive(A11, B12, k) , square_matrix_mutiply_recursive(A12, B22, k), k);
        int** C21 =  add_matrix(square_matrix_mutiply_recursive(A21, B11, k) , square_matrix_mutiply_recursive(A22, B21, k), k);
        int** C22 =  add_matrix(square_matrix_mutiply_recursive(A21, B12, k) , square_matrix_mutiply_recursive(A22, B22, k), k);
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

void print_matrix(int** a, int n, int m)
{
    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < m; j ++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    printf("\n");
}