#include "stdio.h"
#include "stdlib.h"

int main(void)
{
    int size;
    int *array;
    int i = 0;
    int k = 0;
    int temp = 0;
    int swaps = 0;
    int checks = 0;
    printf("Enter the size of array\n");
    scanf("%d", &size);
    array = (int *) malloc(size * sizeof(int));
    printf("Enter the array elements\n");
    while(i<size)
    {
        scanf("%d",(array+i));
        i++;
    }   
    printf("Array looks like this array[%d]=[",size);
    i = 0;
    while (i<size)
    {
        printf("%d,",*(array+i));
        i++;
    }
    
    // sorting
    for(i=0;i<size;i++)
    {
        for(int j=0;j<(size-1);j++)
        {
            if(*(array+j) > *(array+j+1))
            {
                temp = *(array+j);
                *(array+j) = *(array+j+1);
                *(array+j+1) = temp;
                swaps++;
            }
            checks++;
            k = 0;
            while (k<size)
            {
                printf("%d,",*(array+k));
                k++;
            }
            printf("\n");
        }
    }
    
    printf("]\n\nAfter sorting array = [");
    i = 0;
    while (i<size)
    {
        printf("%d,",*(array+i));
        i++;
    }
    printf("]\nTotal checks performed = %d\nTotat swaps needed = %d", checks, swaps);

    free(array);
    return 0;
}
