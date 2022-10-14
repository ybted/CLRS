#include "QUICK_SORT.c"
int randomized_select(int a[], int l, int r, int i)
{
    if (l == r)
        return a[l];
    int p = ramdomized_partition(a, l, r);
    if (p + 1 == i) return a[p];
    else if (p + 1 > i) return randomized_select(a, l, p - 1, i);
    else return randomized_select(a, p + 1, r, i - p - 1);
}