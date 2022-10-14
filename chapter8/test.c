#include <stdio.h>
#include <string.h>
#include "LINEAR_SORT.c"

int main()
{
    int a[] = {6, 0, 2, 0, 1, 3, 4, 6, 1, 3, 2};
    int b[11]; 
    counting_sort(a, b, 11, 20);
    for (int i = 0; i < 11; i ++)
        printf("%d ", b[i]);
    printf("\n");
}
