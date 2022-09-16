#include <iostream>
#include <stdlib.h>

struct  Arvore
{
    int id;
    Arvore *direita;
    Arvore *esquerda;
};

Arvore *inserir( Arvore *raiz, int elemento){

    if(raiz == NULL){

        raiz = (Arvore*)malloc(sizeof(Arvore));

        raiz->id = elemento;
        raiz->direita = NULL;
        raiz->esquerda = NULL;

        return raiz;
    }
    else{

        if(raiz->id > elemento){

            raiz->esquerda = inserir(raiz->esquerda, elemento);
        }

        if(raiz->id < elemento){

            raiz->direita = inserir(raiz->direita, elemento);
        }
    return raiz;
    }
}
void printArvore(Arvore *raiz){

    if(raiz == NULL){
        printf("NULL");
    }
    else{
        printf("(");
        printArvore(raiz->esquerda);
        printf(")");

        printf(",id: %d,", raiz->id);

        printf("(");
        printArvore(raiz->direita);
        printf(")");
    }
}
int main(){

    Arvore *raiz = NULL;

    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 6);
    raiz = inserir(raiz, 3);
    raiz = inserir(raiz, 4);
    raiz = inserir(raiz, 7);
    raiz = inserir(raiz, 2);

    printArvore(raiz);

    return 0;
}