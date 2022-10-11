void merge(int a[], int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int b[n1 + 1];
    int c[n2 + 1];
    for (int i = l, j = 0; i <= mid; i ++, j ++)
        b[j] = a[i];
    for (int i = mid + 1, j = 0; i <= r; i ++, j ++)
        c[j] = a[i];
    b[n1] = INT_MAX;
    c[n2] = INT_MAX;
    int index = l;
    int i = 0, j = 0;
    while (index <= r)
    {
        if (b[i] <= c[j]) {
            a[index] = b[i];
            index ++;
            i ++;
        } else {
            a[index] = c[j];
            index ++;
            j ++;
        }
    }    
}

void merge_sort(int a[], int l, int r)
{
    if (l < r) {
        int mid = (l + r) / 2;
        merge_sort(a, l, mid);
        merge_sort(a, mid + 1, r);
        merge(a, l, mid, r);
    }
}

int  count_merge(int a[], int l, int mid, int r)
{
    int cnt = 0;
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int b[n1 + 1];
    int c[n2 + 1];
    for (int i = l, j = 0; i <= mid; i ++, j ++)
        b[j] = a[i];
    for (int i = mid + 1, j = 0; i <= r; i ++, j ++)
        c[j] = a[i];
    b[n1] = INT_MAX;
    c[n2] = INT_MAX;
    int index = l;
    int i = 0, j = 0;
    while (index <= r)
    {
        if (b[i] <= c[j]) {
            a[index] = b[i];
            index ++;
            i ++;
        } else {
            if (i != n1) cnt = cnt + n1 - i;
            a[index] = c[j];
            index ++;
            j ++;
        }
    }    
    return cnt;
}

int count_inversions(int a[], int l, int r)
{
    int cnt = 0;
    if (l < r) {
        int mid = (l + r) / 2;
        cnt = cnt + count_inversions(a, l, mid);
        cnt = cnt + count_inversions(a, mid + 1, r);
        cnt = cnt + count_merge(a, l, mid, r);
        return cnt;
    }
    return cnt;
}




