void INSERTION_SORT_DEC(int a[], int len)
{
    for (int i = 1; i < len; i ++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] < key)
        {
            a[j + 1] = a[j];
            j --;
        }
        a[j + 1] = key;
    }
}