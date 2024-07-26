#include <stdio.h>
#include <stdlib.h>
#include "arrayio.h"
#include "heap.h"

struct heap H;

int main(int argc, char **argv)
{
    H.A = (int *)malloc(argc * sizeof(int));

    char_to_int_array(argv, H.A, 1, argc - 1);

    heapsort(&H, argc - 1);

    print_array(H.A, 1, argc - 1);
    puts("");

    return 0;
}
