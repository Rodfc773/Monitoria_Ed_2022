#include <iostream>
#include <stdlib.h>

struct  Arvore
{
    int id;
    Arvore *direita;
    Arvore *esquerda;
};

//Função para inserir nós na árvore

Arvore *inserir( Arvore *raiz, int elemento){

    //Caso a arvore esteja vazia ou seja uma folha aser criado, alocamos memória para criação do novo nó

    if(raiz == NULL){

        raiz = (Arvore*)malloc(sizeof(Arvore));

        raiz->id = elemento;
        raiz->direita = NULL;
        raiz->esquerda = NULL;

        return raiz;
    }
    //Caso árvore não esteja vazia, percorremos ela de forma que  respeite certas regras para o novo nó ser inserido
    else{
        /*Caso o elemento que se encontra nó for maior que o elemento que queremos inserir:
            Pecorremos a arvore pelo ponteiro da Esquerda*/
        if(raiz->id > elemento){

            raiz->esquerda = inserir(raiz->esquerda, elemento);
        }

        /*Caso o elemento que se encontra nó for menor que o elemento que queremos inserir:
            Pecorremos a arvore pelo ponteiro da Direita*/

        if(raiz->id < elemento){

            raiz->direita = inserir(raiz->direita, elemento);
        }
    return raiz;
    }
}
void printArvore(Arvore *raiz){

    //Caso o nó não exista, printamos NULL
    if(raiz == NULL){
        printf("NULL");
    }
    // Printa a arvore no método IN-ORDEM
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