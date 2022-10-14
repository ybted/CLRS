void counting_sort(int a[], int b[], int len, int k)
{
    int c[k];
    memset(c, 0, sizeof(c));
    for (int i = 0; i < len; i ++)
        c[a[i]] ++;
    for (int i = 1; i < k; i ++)
        c[i] = c[i] + c[i - 1];
    for (int i = len - 1; i >= 0; i --)
    {
        b[c[a[i]] - 1] = a[i];
        c[a[i]] --;
    }
}

void BUCKET_SORT(int a[], int len)
{
    
}