#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main()
{
	int variable,size,origsize;
	int input = 0;
	int *ptr;
	int *table;
	printf("Enter the number of blocks\n");
	scanf_s("%d",&size);
	origsize = size;
	ptr = (int *)__vcrt_malloc_normal(size * sizeof(int));
	if (ptr == NULL) {
		exit(1);
	}
	printf("\nAddress of the first byte = 0x%x\n", *ptr);
	printf("Enter the numbers\n");
	for (table = ptr; table < (ptr + size); table++) {
		scanf_s("%d", table);
	}
	printf("first step COMPLETED\n");
	for (table = ptr+size-1; table >= ptr; table--) {
		printf("%d - 0x%d\n", *table, table);
	}
	getchar();
	getchar();
	return 0;
}