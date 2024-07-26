#ifndef ARRAYIO_H
#define ARRAYIO_H

#include <stdio.h>

void scan_array(int A[], int p, int q)
{
	for (int i = p; i <= q; i ++)
	{
		scanf("%d", &A[i]);
	}
	return;
}

void print_array(int A[], int p, int q)
{
	for (int i = p; i <= q; i ++)
	{
		printf("%d ", A[i]);
	}
	return;
}

#endif // ARRAYIO_H
