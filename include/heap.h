#ifndef HEAP_H
#define HEAP_H

// heap data structure
// an array A with the heap-size attribute
struct heap
{
    int *A;
    int heap_size;
};

typedef struct heap heap;

// given the index i of a node
// compute the index of its parent
int heap_parent(int i);

// given the index i of a node
// compute the index of its left child
int heap_left(int i);

// given the index i of a node
// compute the index of its right child
int heap_right(int i);

// maintaining the max-heap property
void max_heapfy(struct heap *H, int i);

// building a max-heap
void build_max_heap(struct heap *H, int n);

void heapsort(struct heap *H, int n);

int max_heap_maximum(struct heap *H);

int max_heap_extract_max(struct heap *H);

void max_heap_increase_key(struct heap *H, int i, int k);

void max_heap_insert(struct heap *H, int i, int n);

typedef struct pq_item
{
    int key;
    void *data;
} pq_item;

// treat each array element as a pointer to an object
// each such object has an attribute key
// for a heap inplemented by an array A, we refer to A[i]->key
typedef struct priority_queue
{
    struct pq_item **A;
    int size;
} pq;

// maintaining the max-priority queue property
// exchanging pointers
void max_pq_heapfy(pq *Q, int i);

// building a max-priority queue
void build_max_pq(pq *Q, int n);

// return the element with the largest key
struct pq_item *max_pq_maximum(pq *Q);

struct pq_item *max_pq_extract_max(pq *Q);

// use the idea of the inner loop of insertion-sort
// to reduce the three assignments to just one assignment
void max_pq_increase_key(pq *Q, int i, int k);

void max_pq_insert(pq *Q, pq_item *x, int n);


// maintaining the min-priority queue property
// exchanging pointers
void min_pq_heapfy(pq *Q, int i);

// building a min-priority queue
void build_min_pq(pq *Q, int n);

// return the element with the smallest key
struct pq_item *min_pq_minimum(pq *Q);

struct pq_item *min_pq_extract_min(pq *Q);

// use the idea of the inner loop of insertion-sort
// to reduce the three assignments to just one assignment
void min_pq_decrease_key(pq *Q, int i, int k);

void min_pq_insert(pq *Q, pq_item *x, int n);

#endif // HEAP_H
