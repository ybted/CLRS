void quick_sort(int a[], int l, int r)
{
    if (l >= r) return ;
    int i = l, j = r;
    int mid = (l + r) / 2;
    while (i <= j)
    {
        while (a[i] < a[mid]) i ++;
        while (a[j] > a[mid]) j --;
        if (i <= j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i ++;
            j --;
        }
    }
    quick_sort(a, l, j);
    quick_sort(a, i, r);
}

int partition(int a[], int l, int r)
{
    int x = a[r];
    int i = l - 1;
    for (int j = l; j <= r - 1; j ++)
    {
        if (a[j] <= x)
        {
            i ++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[i + 1];
    a[i + 1] = a[r];
    a[r] = temp;
    return i + 1;
}

void QUICK_SORT(int a[], int l, int r)
{
    if (l < r)
    {
        int m = partition(a, l, r);
        QUICK_SORT(a, l, m - 1);
        QUICK_SORT(a, m + 1, r);
    }
}

int ramdomized_partition(int a[], int l, int r)
{
    srand((unsigned) time(NULL));
    int i = rand() % (r - l + 1) + l;
    int temp = a[i];
    a[i] = a[r];
    a[r] = temp;
    return partition(a, l, r);
}

void randomized_quicksort(int a[], int l, int r)
{
    if (l < r)
    {
        int q = ramdomized_partition(a, l, r);
        randomized_quicksort(a, l, q - 1);
        randomized_quicksort(a, q + 1, r);
    }
} 