#ifndef HEAP_H
#define HEAP_H

// heap data structure
// an array A with the heap-size attribute
struct heap
{
    int *A;
    int heap_size;
};

int parent(int i);

int left(int i);

int right(int i);

// maintaining the max-heap property
void max_heapfy(struct heap *H, int i);

// building a max-heap
void build_max_heap(struct heap *H, int n);

void heapsort(struct heap *H, int n);

#endif // HEAP_H
