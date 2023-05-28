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

int Pertence(Arvore *raiz, int elem){
    if(raiz == NULL) return 0;
    else{
        if (raiz->id == elem){
            return 1;
        }
        else if(raiz->id < elem) return Pertence(raiz->direita, elem);
        else return Pertence(raiz->esquerda, elem);
    }
}

void Intersection(Arvore *tree1, Arvore *tree2, int *array, int *n){
    if(tree1 == NULL) return;
    else{
        Intersection(tree1->esquerda, tree2, array,n);
        if(Pertence(tree2, tree1->id)){
            //printf("Entrei aqui, logo meu valor é %d\n", tree1->id);
            array[tree1->id] = tree1->id;
            (*n) += 1;
        }
        Intersection(tree1->direita, tree2, array, n);
    }
}
void CriandoArvoreIntersect(Arvore **tree3, int intersect[], int n){

    int meio = (n-1)/2;
    *tree3 = inserir(*tree3, intersect[meio]);

    for (int i = 0; i < n; i++)
    {
        *tree3 = inserir(*tree3, intersect[i]);
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
    Arvore *tree3 = NULL;

    tree1 = inserir(tree1, 5);
    tree1 = inserir(tree1, 6);
    tree1 = inserir(tree1, 3);
    tree1 = inserir(tree1, 4);
    tree1 = inserir(tree1, 7);
    tree1 = inserir(tree1, 2);
    tree1 = inserir(tree1, 15);
    tree1 = inserir(tree1, 11);
    tree1 = inserir(tree1, 28);

    tree2 = inserir(tree2, 10);
    tree2 = inserir(tree2, 6);
    tree2 = inserir(tree2, 15);
    tree2 = inserir(tree2, 12);
    tree2 = inserir(tree2, 7);
    tree2 = inserir(tree2, 20);
    tree2 = inserir(tree2, 11);
    tree2 = inserir(tree2, 3);
    tree2 = inserir(tree2, 2);

    int array[50] = {0};
    int n = 0;

    Intersection(tree1, tree2, array, &n);

    int instersec[n];
    printf("\nTamanho da Interseção: %d\n", n);
    printf("Interseção: ");

    int j = 0;
    for (int i = 0; i < 50; i++){
        if(array[i] != 0){

            instersec[j] = array[i];
            printf("%d, ", instersec[j]);

            j += 1;
        }
    }

    CriandoArvoreIntersect(&tree3, instersec, n);

    
    printf("\n");

    printf("Arvore1: \n");
    printArvore(tree1);

    printf("\nArvore2: \n");
    printArvore(tree2);

    printf("\nArvore3: \n");
    printArvore(tree3);
    return 0;
}
