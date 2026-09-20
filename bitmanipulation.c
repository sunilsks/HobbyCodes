#include <stdio.h>
#include <stdlib.h>
#include "bitmanipulation.h"

int main(void)
{
    unsigned int len, data, count, type;
    unsigned int width;

    printf("Select the size of the data\n");
    printf("[1] - 8 bits\n[2] - 16 bits\n[3] - 24 bits\n[4] - 32 bits\n");

    if (scanf("%u", &len) != 1 || len < 1 || len > 4) {
        printf("Invalid size\n");
        return 1;
    }

    width = len * 8;

    printf("Enter the %u-bit data: ", width);
    if (scanf("%u", &data) != 1) {
        printf("Invalid data\n");
        return 1;
    }
    printf("Data input %x\n",data);
    printf("Select the operation\n");
    printf("[1] - CLEAR\n[2] - SET\n[3] - INVERT\n");

    if (scanf("%u", &type) != 1 || type < 1 || type > 3) {
        printf("Invalid operation\n");
        return 1;
    }

    printf("Enter the number of bits you want to alter: ");
    if (scanf("%u", &count) != 1) {
        printf("Invalid count\n");
        return 1;
    }

    unsigned int *bits = calloc(count, count * sizeof(*bits));

    if (bits == NULL && count > 0) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (unsigned int i = 0; i < count; i++) {
        printf("Enter bit position %u: ", i + 1);

        if (scanf("%u", &bits[i]) != 1 || bits[i] >= width) {
            printf("Invalid bit position\n");
            free(bits);
            return 1;
        }

        unsigned int mask = 1u << bits[i];

        if (type == 1) {
            data &= ~mask;       // CLEAR
        } else if (type == 2) {
            data |= mask;        // SET
        } else {
            data ^= mask;        // INVERT
        }
    }

    printf("Result: %u\n", data);
    printf("Result in hexadecimal: 0x%X\n", data);

    free(bits);
    return 0;
}