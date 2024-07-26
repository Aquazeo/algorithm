#include <stdio.h>
#include <stdlib.h>
#include "arrayio.h"
#include "heap.h"

struct heap H;

int main(int argc, char **argv)
{
    H.A = (int *)malloc(argc * sizeof(int));

    for (int i = 1; i < argc; i ++ )
    {
        H.A[i] = atoi(argv[i]);
    }

    heapsort(&H, argc - 1);

    print_array(H.A, 1, argc - 1);
    puts("");

    return 0;
}
