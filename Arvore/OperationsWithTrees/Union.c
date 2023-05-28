#include <stdio.h>
#include <stdlib.h>

typedef struct  Arvore
{
    int id;
    struct Arvore *direita;
    struct Arvore *esquerda;
} Arvore;

Arvore *inserir(Arvore *raiz, int elemento){
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

//Pecorre a  tree2 no sentido pre ordem, e vai adicionando os elemtos de tree2 em tree1
void UnionCall(Arvore **tree1, Arvore *tree2){

   if(tree2 == NULL) return;
   else{

        UnionCall(&((*tree1)), tree2->esquerda);
        *tree1 = inserir(*tree1, tree2->id);
        UnionCall(&((*tree1)), tree2->direita);
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
    Arvore *tree1 = NULL;
    Arvore *tree2 = NULL;

    tree1 = inserir(tree1, 7);
    tree1 = inserir(tree1, 2);
    tree1 = inserir(tree1, 28);

    tree2 = inserir(tree2, 10);
    tree2 = inserir(tree2, 6);
    tree2 = inserir(tree2, 15);
    tree2 = inserir(tree2, 20);
    tree2 = inserir(tree2, 11);


    printf("Arvore1 antes da união: \n");
    printArvore(tree1);

    UnionCall(&tree1, tree2);
    
    printf("\n");

    printf("\nArvore2: \n");
    printArvore(tree2);

     printf("\nArvore1 Depois da união: \n");
    printArvore(tree1);

    return 0;
}
