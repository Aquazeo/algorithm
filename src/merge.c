#include <stdio.h>
#include "merge.h"

// copy the two subarrays into temporary arrays L and R
// merge the values in L and R back into A
void merge(int A[], int p, int q, int r)
{
    int nl = q - p + 1;
    int nr = r - q;
    int L[nl], R[nr];
    for(int i = 0; i < nl; i ++)
    {
        L[i] = A[p + i];
    }
    for (int i = 0; i < nr; i ++)
    {
        R[i] = A[q + i + 1];
    }

    int i = 0;
    int j = 0;
    int k = p;

    while (i < nl && j < nr)
    {
        if (L[i] < R[j])
        {
            A[k] = L[i];
            i ++;
        }
        else
        {
            A[k] = R[j];
            j ++;
        }
        k ++;
    }

    while (i < nl)
    {
        A[k] = L[i];
        i ++;
        k ++;
    }
    while (j < nr)
    {
        A[k] = R[j];
        j ++;
        k ++;
    }
    return;
}

void merge_sort(int A[], int p, int r)
{
    if (p >= r)
        return;
    int q = (p + r) >> 1;

    merge_sort(A, p, q);
    merge_sort(A, q + 1, r);

    merge(A, p, q, r);
    return;
}
