#include <stdio.h>
#include <stdlib.h>

void swap_ptr(void **lhs, void **rhs)
{
    void *temp = *lhs;
    *lhs = *rhs;
    *rhs = temp;
    return;
}

int heap_parent(int i)
{
    return i >> 1;
}

int heap_left(int i)
{
    return i << 1;
}

int heap_right(int i)
{
    return (i << 1) + 1;
}

typedef struct pq_item
{
    int key;
    void *data;
} pq_item;

// treat each array element as a pointer to an object
// each such object has an attribute key
// for a heap inplemented by an array A, we refer to A[i]->key
typedef struct min_priority_queue
{
    struct pq_item **A;
    int size;
} min_pq;

// maintaining the min-priority queue property
// exchanging pointers
void min_pq_heapfy(min_pq *Q, int i);

// building a min-priority queue
void build_min_pq(min_pq *Q, int n);

// return the element with the smallest key
struct pq_item *min_pq_minimum(min_pq *Q);

struct pq_item *min_pq_extract_min(min_pq *Q);

void min_pq_decrease_key(min_pq *Q, int i, int k);

void min_pq_insert(min_pq *Q, pq_item *x, int n);

struct function
{
    int A, B, C;
    int x;
};

min_pq pq;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    pq.A = (struct pq_item **)malloc(n * sizeof(struct pq_item *));

    struct function *f;
    struct pq_item *item;
    for (int i = 1; i <= n; i ++)
    {
        f = (struct function *)malloc(n * sizeof(struct function));
        scanf("%d%d%d", &f->A, &f->B, &f->C);
        f->x = 1;

        item = (struct pq_item *)malloc(sizeof(struct pq_item));
        item->key = f->A + f->B + f->C;
        item->data = (void *)f;
        min_pq_insert(&pq, item, n);
    }

    int ans[m];
    int index = 0;
    struct pq_item *max;
    while (index < m)
    {
        max = min_pq_extract_min(&pq);
        ans[index] = max->key;
        index ++;

        struct function *func = (struct function *)(max->data);
        func->x ++;
        max->key = func->A * func->x * func->x + func->B * func->x + func->C;

        min_pq_insert(&pq, max, n);
    }

    for (int i = 0; i < m; i ++)
        printf("%d ", ans[i]);
    
    puts("");

    return 0;
}

void min_pq_heapfy(min_pq *Q, int i)
{
    int l = heap_left(i);
    int r = l + 1;
    int smallest = i;

    if (l <= Q->size && Q->A[l]->key < Q->A[i]->key)
        smallest = l;
    if (r <= Q->size && Q->A[r]->key < Q->A[smallest]->key)
        smallest = r;
    
    if (smallest != i)
    {
        swap_ptr((void *)&Q->A[i], (void *)&Q->A[smallest]);
        min_pq_heapfy(Q, smallest);
    }
    return;
}

void build_min_pq(min_pq *Q, int n)
{
    Q->size = n;
    for (int i = n >> 1; i >= 1; i --)
        min_pq_heapfy(Q, i);
    return;
}

struct pq_item *min_pq_minimum(min_pq *Q)
{
    if (Q->size < 1)
        fprintf(stderr, "heap underflow\n");
    return Q->A[1];
}

struct pq_item *min_pq_extract_min(min_pq *Q)
{
    struct pq_item *min = min_pq_minimum(Q);
    Q->A[1] = Q->A[Q->size];
    Q->size --;
    min_pq_heapfy(Q, 1);
    return min;
}

void min_pq_decrease_key(min_pq *Q, int i, int k)
{
    if (k > Q->A[i]->key)
        fprintf(stderr, "new key is larger than current key\n");

    
    Q->A[i]->key = k;
    while (i > 1 && Q->A[heap_parent(i)]->key > Q->A[i]->key)
    {
        swap_ptr((void *)&Q->A[i], (void *)&Q->A[heap_parent(i)]);
        i = heap_parent(i);
    }
    return;
}

void min_pq_insert(min_pq *Q, pq_item *x, int n)
{
    if (Q->size == n)
        fprintf(stderr, "heap overflow\n");

    Q->size ++;
    int k = x->key;
    x->key = 0x7fffffff;
    Q->A[Q->size] = x;
    min_pq_decrease_key(Q, Q->size, k);
    return;
}
