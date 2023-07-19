#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifndef ADT_H
#define ADT_H

/*
typedef struct node {
    char *data;
    struct node *next;
} Node;

// Define the Stack structure
typedef struct stack {
    Node *top;
} Stack;

// YOUR FUNCTION PROTOTYPES HERE
int is_empty(Stack *s);
void push(Stack *s, char *data);
char *pop(Stack *s);
void print_stack(Stack *s);
void init(Stack *s);*/

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE][MAX_SIZE];
    int top;
} Stack;

void print(Stack *stack);
int isfull(Stack *stack);
int isempty(Stack *stack);
char* pop(Stack *stack);
void push(Stack *stack, char *item);
#endif /* ADT_H */