int* find_max_crossing_subarray(int a[], int l, int r, int mid)
{
    int* ans = (int *)malloc(sizeof(int) * 3);
    int left_sum = INT_MIN;
    int temp_sum = 0;
    int left = 0;
    for (int i = mid; i >= l; i --)
    {
        temp_sum += a[i];
        if (temp_sum > left_sum)
        {
            left_sum = temp_sum;
            left = i;
        }
    } 
    int right_sum = INT_MIN;
    temp_sum = 0;
    int right = 0;
    for (int i = mid + 1; i <= r; i ++)
    {
        temp_sum += a[i];
        if (temp_sum > right_sum)
        {
            right_sum = temp_sum;
            right = i;
        }
    }
    ans[0] = left;
    ans[1] = right;
    ans[2] = right_sum + left_sum;
    return ans;
}
int* find_maximum_subarray(int a[], int l, int r)
{
    int* ans = (int*)malloc(sizeof(int) * 3);
    if (l == r) {
        ans[0] = l;
        ans[1] = l;
        ans[2] = a[l];
        return &ans[0];
    }else {
        int mid = (l + r) / 2;
        int *t1 = find_maximum_subarray(a, l, mid);
        int *t2 = find_maximum_subarray(a, mid+1, r);
        int *t3 = find_max_crossing_subarray(a, l, r, mid);
        if (t1[2] >= t2[2] && t1[2] >= t3[2]) return t1;
        if (t2[2] >= t1[2] && t2[2] >= t3[2]) return t2;
        if (t3[2] >= t1[2] && t3[2] >= t2[2]) return t3; 
    }
}