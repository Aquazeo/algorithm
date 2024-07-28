#ifndef HEAP_H
#define HEAP_H

// heap data structure
// an array A with the heap-size attribute
struct heap
{
    int *A;
    int heap_size;
};

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

struct max_priority_queue
{
    
};

#endif // HEAP_H
