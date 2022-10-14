#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "QUICK_SORT.c"

int main()
{
    int a[] = {13, 19, 9, 5, 12, 8, 7, 4, 21, 2, 6, 11};
    quick_sort(a, 0, 11);
    for (int i = 0; i < 12; i ++)
        printf("%d ", a[i]);
    printf("\n");
    
    int b[] = {13, 19, 9, 5, 12, 8, 7, 4, 21, 2, 6, 11};
    QUICK_SORT(b, 0, 11);
    for (int i = 0; i < 12; i ++)
        printf("%d ", b[i]);
    printf("\n");

    int c[] = {13, 19, 9, 5, 12, 8, 7, 4, 21, 2, 6, 11};
    randomized_quicksort(c, 0, 11);
    for (int i = 0; i < 12; i ++)
        printf("%d ", c[i]);
    printf("\n");
}