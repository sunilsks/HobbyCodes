#include "stdio.h"
int gvar;
unsigned int gvar_u;

int main(void)
{
    int var1 = 8;
    printf("Address - %u\n", &var1);
    printf("Address - %u\n", &gvar);
    printf("Address - %u\n\n", &gvar_u);

    printf("Address - 0x%x\n", &var1);
    printf("Address - 0x%x\n", &gvar);
    printf("Address - 0x%x\n\n", &gvar_u);

    printf("Address - 0x%p\n", &var1);
    printf("Address - 0x%p\n", &gvar);
    printf("Address - 0x%p\n", &gvar_u);
    return 0;
}