#include <stdio.h>
#include "core.h"
#include "heap.h"

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

void max_heapfy(struct heap *H, int i)
{
    int l = heap_left(i);
    int r = l + 1;
    int largest = i;

    if (l <= H->heap_size && H->A[l] > H->A[i])
        largest = l;
    if (r <= H->heap_size && H->A[r] > H->A[largest])
        largest = r;
    
    if (largest != i)
    {
        swap(&H->A[i], &H->A[largest]);
        max_heapfy(H, largest);
    }
    return;
}

void build_max_heap(struct heap *H, int n)
{
    H->heap_size = n;
    for (int i = n >> 1; i >= 1; i --)
        max_heapfy(H, i);
    return;
}

void heapsort(struct heap *H, int n)
{
    build_max_heap(H, n);
    for (int i = n; i >= 2; i --)
    {
        swap(&H->A[1], &H->A[i]);
        H->heap_size --;
        max_heapfy(H, 1);
    }
    return;
}

int max_heap_maximum(struct heap *H)
{
    if (H->heap_size < 1)
        fprintf(stderr, "heap underflow\n");
    return H->A[1];
}

int max_heap_extract_max(struct heap *H)
{
    int max = max_heap_maximum(H);
    H->A[1] = H->A[H->heap_size];
    H->heap_size --;
    max_heapfy(H, 1);
    return max;
}

void max_heap_increase_key(struct heap *H, int i, int k)
{
    if (k < H->A[i])
        fprintf(stderr, "new key is smaller than current key\n");

    H->A[i] = k;
    while (i > 1 && H->A[heap_parent(i)] < H->A[i])
    {
        swap(&H->A[i], &H->A[heap_parent(i)]);
        i = heap_parent(i);
    }
    return;
}

void max_heap_insert(struct heap *H, int x, int n)
{
    if (H->heap_size == n)
        fprintf(stderr, "heap overflow\n");

    H->heap_size ++;
    H->A[H->heap_size] = 0x80000000;
    max_heap_increase_key(H, H->heap_size, x);
    return;
}

/* max priority queue */

void max_pq_heapfy(max_pq *Q, int i)
{
    int l = heap_left(i);
    int r = l + 1;
    int largest = i;

    if (l <= Q->size && Q->A[l]->key > Q->A[i]->key)
        largest = l;
    if (r <= Q->size && Q->A[r]->key > Q->A[largest]->key)
        largest = r;
    
    if (largest != i)
    {
        swap_ptr((void *)&Q->A[i], (void *)&Q->A[largest]);
        max_pq_heapfy(Q, largest);
    }
    return;
}

void build_max_pq(max_pq *Q, int n)
{
    Q->size = n;
    for (int i = n >> 1; i >= 1; i --)
        max_pq_heapfy(Q, i);
    return;
}

struct pq_item *max_pq_maximum(max_pq *Q)
{
    if (Q->size < 1)
        fprintf(stderr, "heap underflow\n");
    return Q->A[1];
}

struct pq_item *max_pq_extract_max(max_pq *Q)
{
    struct pq_item *max = max_pq_maximum(Q);
    Q->A[1] = Q->A[Q->size];
    Q->size --;
    max_pq_heapfy(Q, 1);
    return max;
}

void max_pq_increase_key(max_pq *Q, int i, int k)
{
    if (k < Q->A[i]->key)
        fprintf(stderr, "new key is smaller than current key\n");

    
    Q->A[i]->key = k;
    while (i > 1 && Q->A[heap_parent(i)]->key < Q->A[i]->key)
    {
        swap_ptr((void *)&Q->A[i], (void *)&Q->A[heap_parent(i)]);
        i = heap_parent(i);
    }
    return;
}

void max_pq_insert(max_pq *Q, pq_item *x, int n)
{
    if (Q->size == n)
        fprintf(stderr, "heap overflow\n");

    Q->size ++;
    int k = x->key;
    x->key = 0x80000000;
    Q->A[Q->size] = x;
    max_pq_increase_key(Q, Q->size, k);
    return;
}

/* min priority queue */

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
