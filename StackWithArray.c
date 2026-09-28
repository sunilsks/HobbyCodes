#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// Stack : Initialise, push, pop, peek, isFull, isEmpty
#define MAX 10

typedef struct
{
    int array[MAX];
    int top;
} stack_st;

void Initialise(stack_st *stack)
{
    stack->top = -1;
}

bool isEmpty(stack_st *stack)
{
    return stack->top == -1;
}

bool isFull(stack_st *stack)
{
    return stack->top >= (MAX - 1);
}

void push(stack_st *stack, int data)
{
    if (isFull(stack))
    {
        printf("Stack Overflow\n");
        return;
    }

    stack->array[++(stack->top)] = data;
}

int pop(stack_st *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        return -1;
    }

    return stack->array[(stack->top)--];
}

int peek(stack_st *stack)
{
    if (!isEmpty(stack))
    {
        return stack->array[stack->top];
    }

    printf("Stack is empty\n");
    return -1;
}

void printStackPictorial(stack_st *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack view:\n");
        printf("   [ empty ]\n");
        return;
    }

    printf("Stack view (top at the left):\n");
    printf("   --------\n");

    for (int i = stack->top; i >= 0; i--)
    {
        printf("   | %d |\n", stack->array[i]);
    }

    printf("   --------\n");
}

int main(void)
{
    stack_st stack;
    Initialise(&stack);

    int choice;
    int value;

    while (1)
    {
        printf("\n=============================\n");
        printf(":::: Stack Menu :::\n");
        printf("1 - Peek | ");
        printf("2 - Push | ");
        printf("3 - Pop | ");
        printf("4 - Check Empty | ");
        printf("5 - Check Full | ");
        printf("6 - Print Stack | ");
        printf("9 - Exit | \n");
        printf("=============================\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("->Invalid input. Exiting program.\n");
            break;
        }

        switch (choice)
        {
            case 1:
                value = peek(&stack);
                if (!isEmpty(&stack))
                {
                    printf("Top element is: %d\n", value);
                }
                break;

            case 2:
                printf("Enter value to push: ");
                if (scanf("%d", &value) != 1)
                {
                    printf("->Invalid input.\n");
                    break;
                }
                push(&stack, value);
                break;

            case 3:
                value = pop(&stack);
                if (value != -1)
                {
                    printf("->Popped value: %d\n", value);
                }
                break;

            case 4:
                printf("Stack is %s\n", isEmpty(&stack) ? "empty" : "not empty");
                break;

            case 5:
                printf("Stack is %s\n", isFull(&stack) ? "full" : "not full");
                break;

            case 6:
                printStackPictorial(&stack);
                break;

            case 9:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("->Invalid choice. Please choose a valid option.\n");
                break;
        }

        if ((choice == 2) || (choice == 3))
        {
            printStackPictorial(&stack);
        }
    }

    return 0;
}