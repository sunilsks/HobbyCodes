#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
/*store the list of elements in a linked list*/
struct lslinkedlist {
	unsigned int index_u8;
	unsigned int lsdata;
	struct lslinkedlist *next;
	struct lslinkedlist *prev;
};

typedef struct lslinkedlist node;
node *head;
int main()
{
	node *prevnode;
	node *currentnode;
	unsigned int listsize=0;
	printf("Enter the number of lists");
	scanf_s("%u",&listsize);
	head = (node *)malloc(listsize * sizeof(node));
	head->prev = NULL;
	prevnode = head;
	currentnode = head;
	for (int i=0;i<listsize;i++)
	{
		printf("Enter the data for %dth node \n", i);
		scanf_s("%u", &(currentnode->lsdata));
		currentnode->index_u8 = i;
		printf("Successfully stored at %u\n", &currentnode->lsdata);

		if(i==0){
		}else{
			currentnode->prev = prevnode;
		}

		prevnode = currentnode;

		if (i == (listsize - 1)) {
			currentnode->next = NULL;
		}
		else{
			currentnode->next = currentnode++;
		}
	}
	currentnode = head;
	for (int i = 0; i < listsize; i++) {
		printf("|%2.2u |%2.2u |%10.10d |%10.10d|\n", currentnode->index_u8, currentnode->lsdata, currentnode->prev, currentnode->next);
			currentnode++;
	}

	getchar();
	getchar();
	return 0;
}
