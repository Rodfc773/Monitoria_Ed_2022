#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

struct Stack *push(struct Stack *stack, int elemento){

    struct Stack *novoTopo = NULL;
    
    if(stack == NULL){

        stack = (struct Stack*)malloc(sizeof(struct Stack));

        stack->elemento = elemento;
        return stack;
    }

    novoTopo = novoTopo = (struct Stack*)malloc(sizeof(struct Stack));

    novoTopo->elemento = elemento;
    novoTopo->prox = stack;

    return novoTopo;
}
struct Stack *pop(struct Stack *stack){

    if(stack == NULL){
        printf("Pilha já está vazia");

        return NULL;
    }
    struct Stack *aux = stack;

    aux = stack;
    stack = stack->prox;

    free(aux);

    return stack;
}