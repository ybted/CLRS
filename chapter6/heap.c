typedef struct {
    int* a;
    int length;
    int heap_size;
}heap;

heap* init(int array[], int len)
{
    heap* a = (heap*) malloc(sizeof(heap));
    int* b = (int* ) malloc(sizeof(int) * 100);
    for (int i = 0; i < 100; i ++)
        b[i] = array[i];
    a->a = b;
    a->length = 100;
    a->heap_size = len;
    return a;
}

int parent(int i)
{
    return i / 2;
}

int left(int i){
    return 2 * i;
}

int right(int i){
    return 2 * i + 1;
}

void max_heapify(heap* a, int i)
{
    int l = left(i);
    int r = right(i);
    int largest;
    if (l < a->heap_size && a->a[i] < a->a[l])
    {
        largest = l;
    }
    else 
    {
        largest = i;
    }
    if (r < a->heap_size && a->a[largest] < a->a[r])
    {   
        largest = r;
    }
    if (largest != i)
    {
        int temp = a->a[i];
        a->a[i] = a->a[largest];
        a->a[largest] = temp;
        max_heapify(a, largest);
    }
}

void min_heapify(heap* a, int i)
{
    int l = left(i);
    int r = right(i);
    int smallest;
    if (l < a->heap_size && a->a[i] > a->a[l])
    {
        smallest = l;
    }
    else 
    {
        smallest = i;
    }
    if (r < a->heap_size && a->a[smallest] > a->a[r])
    {   
        smallest = r;
    }
    if (smallest != i)
    {
        int temp = a->a[i];
        a->a[i] = a->a[smallest];
        a->a[smallest] = temp;
        min_heapify(a, smallest);
    }
}

void print_heap(heap a)
{
    for (int i = 0; i < a.heap_size; i ++)
        printf("%d ", a.a[i]);
    printf("\n");
}

heap* build_max_heap(int a[], int len)
{
    heap* h = init(a, len);
    for (int i = h->heap_size / 2; i >= 0; i --)
        max_heapify(h, i);
    return h;
}

heap* build_min_heap(int a[], int len)
{
    heap* h = init(a, len);
    for (int i = h->heap_size / 2; i >= 0; i --)
        min_heapify(h, i);
    return h;
}

void heapsort(int a[], int len)
{
    heap* h = build_max_heap(a, len);
    for (int i = h->heap_size - 1; i >= 0; i --)
    {
        int temp = h->a[0];
        h->a[0] = h->a[i];
        h->a[i] = temp;
        h->heap_size --;
        max_heapify(h, 0);
    }
    for (int i = 0; i < len; i ++)
        a[i] = h->a[i];
}

int heap_maximum(heap a)
{
    return a.a[0];
}

int heap_extract_max(heap* a)
{
    if (a->heap_size < 1) {
        printf("heap underflow");
        return -1;
    }
    int max = a->a[0];
    a->a[0] = a->a[a->heap_size - 1];
    a->heap_size -- ;
    max_heapify(a, 0);
    return max;
}

void heap_increase_key(heap *a, int i, int key)
{
    if (key < a->a[i])
    {
        printf("new key is smaller tham current key\n");
        return ;
    }
    a->a[i] = key;
    while (i > 0 && a->a[parent(i)] < a->a[i])
    {
        int temp = a->a[parent(i)];
        a->a[parent(i)] = a->a[i];
        a->a[i] = temp;
        i = parent(i);
    }
}


void max_heap_insert(heap* a, int key)
{
    a->heap_size ++ ;
    a->a[a->heap_size - 1] = INT_MIN;
    heap_increase_key(a, a->heap_size - 1, key);
}