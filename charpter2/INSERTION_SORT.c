void INSERTION_SORT(int a[], int len)
{
    for (int i = 1; i < len; i ++)
    {
        int key = a[i];
        //insert a[i] into the sorted sequence a[1..j-1]
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j --;
        }
        a[j + 1] = key; 
    }
}
int binary_search(int a[], int len, int key)
{
    int l = 0, r = len;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (a[mid] >= key) r = mid;
        else l = mid + 1;
    }
    return l;
}
void insertion_sort_bi(int a[], int len)
{
    for( int i = 1; i < len; i ++)
    {
        int key = a[i];
        int p = binary_search(a, i, key);
        for (int j = i; j > p; j --)
            a[j] = a[j - 1];
        a[p] = key;
    }
}