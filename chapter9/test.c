#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "RANDOMIZED_SELECT.c"

int main()
{
    int a[] = {1,2,3,4,5};
    int ans = randomized_select(a, 0, 4, 3);
    printf("%d", ans);
}