#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
/*store the list of elements in a linked list*/
struct lslinkedlist {
	int lsdata;
	struct lslinkedlist *link;
};

typedef struct lslinkedlist node;
node *head;

int main()
{
	unsigned int lssizeoflist = 0u;
	node *storedhead;
	printf("Enter the size of list\n");
	scanf_s("%d", &lssizeoflist);

	head = (node *) malloc(lssizeoflist * sizeof(node));
	storedhead = head;
	printf("Enter the elements\n");

	for (int i = 0; i < lssizeoflist; i++) {
		scanf_s("%d", &head->lsdata);
		printf("Successfully stored at %d\n", &head->lsdata);
		head->link = head++;
	}
	head->link = NULL;
	
	printf("\n------Completed----------\n");

	//do {
	//	printf("Elements = %d\n", head->lsdata);
	//	head++;
	//} while (head->link->link != NULL);

	for (int j = 0; j < lssizeoflist; j++) {
		printf("Data[%d] = %d", j, storedhead->lsdata);
		if(storedhead->link->link == NULL)
			printf("Data[%d] = %d", j, storedhead->link->lsdata);
		storedhead++;
	}

	getchar();
	getchar();
	return 0;
}