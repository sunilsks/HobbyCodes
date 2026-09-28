#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000

// Stack structure
struct Stack {
    char arr[MAX];
    int top;
};

// Push operation
void push(struct Stack* s, char c) 
{
    s->arr[++(s->top)] = c;
}

// Pop operation
char pop(struct Stack* s) {
    return s->arr[(s->top)--];
}

// Function to reverse string using stack
char* reverseString(char* s) {
    int length = strlen(s);
    struct Stack st;
    st.top = -1;

    // Push all characters onto stack
    for (int i = 0; i < length; i++) {
        push(&st, s[i]);
    }

    // Pop characters back into new string
    char* reversed = (char*)malloc((length + 1) * sizeof(char));
    for (int i = 0; i < length; i++) {
        reversed[i] = pop(&st);
    }
    reversed[length] = '\0'; // null terminate

    return reversed;
}
