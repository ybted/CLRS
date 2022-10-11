#include <limits.h>
void CHOOSING_SORT(int a[], int len)
{
    for (int i = 0; i < len; i ++)
    {
        int min = INT_MAX;
        int index;
        for (int j = i; j < len; j ++)
        {
            if (a[j] < min)
            {
                index = j;
                min = a[j];
            } 
        }
        // swap two numbers
        int temp = a[i];
        a[i] = min;
        a[index] = temp;
    }
}