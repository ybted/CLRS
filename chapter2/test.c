#include <stdio.h>
#include "INSERTION_SORT.c"
#include "INSERTION_SORT_DEC.c"
#include "CHOOSING.c"
#include "MERGE_SORT.c"
int main()
{
    int a[] = {5, 2, 4, 6, 1, 3};
    insertion_sort_bi(a, 6);
    printf("ascending sort: ");
    for (int i = 0; i < 6; i ++)
        printf("%d ", a[i]);
    printf("\n");
    INSERTION_SORT_DEC(a, 6);
    printf("descending sort: ");
    for (int i = 0; i < 6; i ++)
        printf("%d ", a[i]);
    printf("\n");
    
    int b[] = {9, 2, 3, 5, 7, 6, 8, 1, 4};
    CHOOSING_SORT(b, 9);
    printf("choosing sort: ");
    for (int i = 0; i < 9; i ++)
        printf("%d ", b[i]);
    printf("\n");
    
    int c[] = {2, 3, 8, 6, 1};
    int cnt = count_inversions(c, 0, 4);
    printf("merge sort: ");
    for (int i = 0;  i < 5; i ++)
        printf("%d ", c[i]);
    printf("\n");
    printf("cnt : %d", cnt);
}