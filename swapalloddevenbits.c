#include "stdio.h"

unsigned int number = 0;
int main()
{
    unsigned int temp = 0;
    unsigned int mask = 0;
    printf("provide the decimal number\n");
        scanf("%u", &number);
    temp = number;
        for (int i = 0; i < 16; i++)
    {
        if(((number >> (i*2)) & 0x3) == 0x1)
        {
            mask = 0;
            mask = (0x2 << (i*2)); // prepare masked value
            temp = mask | (temp & ~(0x3 << (i*2))); // Clear masked range and append the data
            //printf("1:i am here %d\n", i);
        }
        else if((number >> (i*2) & 0x3) == 0x2)
        {
            mask = 0;
            mask = (0x1 << (i*2)); // prepare masked value
            temp = mask | (temp & ~(0x3 << (i*2))); // Clear masked range and append the value
            //printf("2:i am here %d\n", i);
        }
        else
        {
            // nothing
            //printf("3:i am here %d\n", i);
        }
    }
        printf("%u\n", temp);
    return 0;
}