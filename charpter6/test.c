#include <stdio.h>
#include <malloc.h>
#include "heap.c"

void print(int* a, int len)
{
    for (int i = 0; i < len; i ++)
        printf("%d ",a[i]);
    printf("\n");
}
int main()
{
    int a[] = {27, 17, 3, 16, 13, 10, 1, 5 ,7, 12};
    heap* h1 = build_max_heap(a, 10);
    heap* h2 = build_min_heap(a, 10);   
    
    print_heap(*h1);
    print_heap(*h2);
    heapsort(a, 10);
    for (int i =0 ; i < 10; i ++)
        printf("%d ", a[i] );
}