#include "adt.h"
#include <stdio.h>
#include <string.h>


// YOUR SOLUTION



#define MAX_SIZE 100

void push(Stack *stack, char *item) {
    if (stack->top < MAX_SIZE) {
        strcpy(stack->data[stack->top], item);
        stack->top++;
    } else {
        printf("Stack overflow\n");
    }
}

char* pop(Stack *stack) {
  
       stack->top--;
        return stack->data[stack->top];
}

int isempty(Stack *stack) {
    return stack->top == 0;
}

int isfull(Stack *stack) {
    return stack->top == MAX_SIZE;
}

void print(Stack *stack) {
    int i;
    if (stack->top <= 0)
    {
        printf("1");
        exit(1);
    }
    for (i = 0; i < stack->top; i++) {
        printf("%s", stack->data[i]);
    }
}