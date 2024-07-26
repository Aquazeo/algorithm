#include <stdio.h>
#include <stdlib.h>
#include "arrayio.h"
#include "heap.h"

struct heap H;

int main(void)
{
	int num;
	printf("Enter the number of elements: ");
	scanf("%d", &num);
	
	H.heap_size = 0;
	H.A = (int *)malloc((num + 1) * sizeof(int));
	
	scan_array(H.A, 1, num);
	heapsort(&H, num);
	print_array(H.A, 1, num);	
	puts("");
	//printf("%d", H.A[0]);
	//printf("%d", H.heap_size);

	return 0;
}
