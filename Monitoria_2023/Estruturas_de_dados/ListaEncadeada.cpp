#include <iostream>
#include <stdlib.h>

//Struct para a criacao da lista:

typedef struct Lista
{
    int chave; // valor do conteudo
    Lista *prox ;// ponteiro para o proximo elemento da lista
};

//Funcao que dar inicio a lista

Lista *CreateList(Lista *head, int chave){

    if(head == NULL){

        head =  (Lista*)malloc(sizeof(Lista)); // A funcao malloc ira alocar o espaco nescessario na memoria para armezenar a lista
        head->chave = chave; // Para acessar valores de estruturas dinamicas se usa "->"
        head->prox = NULL;

        // Custo para criar a lista O(1)

        return head;
    }
    else{

        Lista *novo, *aux = head;

        //Percorre a lista para achar um posicao vaga: O(n)
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        
        novo = (Lista*)malloc(sizeof(Lista));
        novo->chave = chave;
        novo->prox = NULL;

        aux->prox = novo;

        return head;
    }

}
void PrintList(Lista *head){

    printf("[");
    while (head != NULL)
    {   
        printf("%d, ", head->chave);
        head = head->prox;
    }
    printf("]\n");
    
}
int main(){

    Lista *listaTeste = NULL;

    //listaTeste = CreateList(listaTeste, 1);

   
    for (int i = 0; i < 10; i++)
    {
        listaTeste = CreateList(listaTeste, i);
    }

    PrintList(listaTeste);
    return 0;
}