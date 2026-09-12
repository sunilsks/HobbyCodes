#include <stdio.h>
//==============================================================================
int main() {
    // An array of 4 pointers, each pointing to a string literal in memory
    const char *actions[4] = {
        "Start Game",
        "Load Saved File",
        "Options",
        "Exit"
    };

    printf("--- GAME MENU ---\n");
    for (int i = 0; i < 4; i++) {
        // actions[i] retrieves the pointer to the string
        printf("%d. %s\n", i + 1, actions[i]);
    }

    return 0;
}
//==============================================================================
int main2() {
    int classA[2] = {85, 90};
    int classB[4] = {76, 88, 92, 95};
    int classC[3] = {62, 70, 81};

    // Array of 3 pointers holding the addresses of the three distinct arrays
    int *school[3] = {classA, classB, classC};
    int classSizes[3] = {2, 4, 3};

    for (int i = 0; i < 3; i++) {
        printf("Class %c grades: ", 'A' + i);
        for (int j = 0; j < classSizes[i]; j++) {
            // school[i] gets the row pointer; [j] accesses the element
            printf("%d ", school[i][j]);
        }
        printf("\n");
    }
    return 0;
}
//==============================================================================
// The function expects a pointer to an array of 3 integers (a row)
void printMatrix(int (*matrixPtr)[3], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 3; j++) {
            // matrixPtr[i][j] works seamlessly
            printf("%d ", matrixPtr[i][j]);
        }
        printf("\n");
    }
}

int main3() {
    // A 2D matrix consisting of 2 rows, where each row is an array of 3 ints
    int grid[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    // grid decays into a pointer to its first row: int (*)[3]
    printMatrix(grid, 2); 

    return 0;
}
//==============================================================================

int main4() {
    int dataset[3][4] = {
        {10, 11, 12, 13}, // Row 0
        {20, 21, 22, 23}, // Row 1
        {30, 31, 32, 33}  // Row 2
    };

    // Declare a pointer to an array of 4 integers
    int (*rowPtr)[4];

    // Point specifically to Row 1 of the dataset
    rowPtr = &dataset[1]; 

    printf("Row 1, Element 2: %d\n", (*rowPtr)[2]); // Outputs 22

    return 0;
}
