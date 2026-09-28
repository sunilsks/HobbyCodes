#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Push: insert at the beginning
void push(struct Node** top, int value) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Stack Overflow\n");
        return;
    }
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

// Pop: remove from the beginning
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node* temp = *top;
    int popped = temp->data;
    *top = temp->next;
    free(temp);
    return popped;
}

// Peek: view top element
int peek(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

// Check if stack is empty
int isEmpty(struct Node* top) {
    return top == NULL;
}

void printStackPictorial(struct Node* top) {
    if (top == NULL) {
        printf("Stack view:\n");
        printf("   [ empty ]\n");
        return;
    }

    printf("Stack view (top at the left):\n");
    printf("   --------\n");

    while (top != NULL) {
        printf("   | %d |\n", top->data);
        top = top->next;
    }

    printf("   --------\n");
}

int main(void) {
    struct Node* top = NULL;
    int choice, value;

    while (1) {
        printf("\n=============================\n");
        printf("Stack Menu\n");
        printf("1 - Peek\n");
        printf("2 - Push\n");
        printf("3 - Pop\n");
        printf("4 - Check Empty\n");
        printf("5 - Print Stack\n");
        printf("9 - Exit\n");
        printf("=============================\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting program.\n");
            break;
        }

        switch (choice) {
            case 1: // peek
                value = peek(top);
                if (!isEmpty(top)) {
                    printf("Top element is: %d\n", value);
                }
                break;

            case 2: // push
                printf("Enter value to push: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input.\n");
                    break;
                }
                push(&top, value);
                break;

            case 3: // pop
                value = pop(&top);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;

            case 4:
                printf("Stack is %s\n", isEmpty(top) ? "empty" : "not empty");
                break;

            case 5:
                printStackPictorial(top);
                break;

            case 9:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice. Please choose a valid option.\n");
                break;
        }

        if (choice != 9) {
            printStackPictorial(top);
        }
    }

    return 0;
}
