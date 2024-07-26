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

void char_to_int_array(char **C, int A[], int p, int q)
{
	for (int i = p; i <= q; i ++)
	{
		A[i] = atoi(C[i]);
	}
	return;
}

#endif // ARRAYIO_H
