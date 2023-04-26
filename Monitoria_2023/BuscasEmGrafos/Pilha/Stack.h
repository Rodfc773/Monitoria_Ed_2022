#include <stdio.h>
#include<stdlib.h>

struct Stack
{
    int elemento;
    struct Stack *prox;
};

struct Stack *push(struct Stack *stack, int elemento);
struct Stack *pop(struct Stack *stack);
