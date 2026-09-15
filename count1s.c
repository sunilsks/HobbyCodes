// count the number of 1s 
#include "stdio.h"
#include "string.h"
int number = 0;
int count1s(int data);
int main()
{
    printf("Enter the number to calculate the number of bits set\n");
    scanf("%d", &number);
    printf(" Here is the hexadecimal version of it 0x%x\n", number);
    printf("There are %d 1's in %d decimal number\n", count1s(number), number);
    getchar();
    return 0;
}

int count1s(int data)
{
    static int count = 0;
    while(data)
    {   
        data &= (data - 1);
        count ++;
    }
    return count;
}