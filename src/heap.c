#include "core.h"
#include "heap.h"

int parent(int i)
{
	return i >> 1;
}

int left(int i)
{
	return i << 1;
}

int right(int i)
{
	return (i << 1) + 1;
}

void max_heapfy(struct heap *H, int i)
{
	int l = left(i);
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