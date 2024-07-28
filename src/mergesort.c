#include <stdio.h>
#include "arrayio.h"
#include "merge.h"

int main()
{
    int num;
    printf("Enter the number of elements: ");
    scanf("%d", &num);

    int A[num];

    scan_array(A, 0, num - 1);
    merge_sort(A, 0, num - 1);
    print_array(A, 0, num - 1);

    return 0;
}
