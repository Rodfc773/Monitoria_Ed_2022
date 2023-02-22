#include <iostream>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

using namespace std;

struct arvore
{
    arvore *direita;
    arvore *esquerda;
    int elemento;
};
arvore *Inserir(arvore *raiz, int elem)
{
    if(raiz == NULL)
    {
        raiz = (arvore*)malloc(sizeof(arvore));
        raiz->direita = NULL;
        raiz->esquerda = NULL;
        raiz->elemento = elem;
        

        return raiz;
    }
    else if(raiz->elemento < elem)
    {
        raiz->direita = Inserir(raiz->direita, elem);
    }
    else if (raiz->elemento > elem)
    {
        raiz->esquerda = Inserir(raiz->esquerda, elem);
    }
    return raiz;
    
}
arvore *Remover(arvore *raiz, int elem)
{
    if (raiz == NULL)
    {
        return NULL;
    }
    else
    {
        if (raiz->elemento < elem)
        {
            raiz->direita = Remover(raiz->direita, elem);
        }
        else if(raiz->elemento > elem)
        {
            raiz->esquerda = Remover(raiz->esquerda, elem);
        }
        else
        {
            if (raiz->esquerda == NULL && raiz->direita == NULL)
            {
                free(raiz);
                return NULL;
            }
            else if(raiz->direita == NULL)
            {
                arvore *aux = raiz;
                raiz = raiz->esquerda;
                free(aux);

            }
            else if(raiz->esquerda == NULL)
            {
                arvore *aux = raiz;
                raiz = raiz->direita;

                free(aux);
            }
            else
            {
                arvore *aux = raiz->esquerda;

                while (aux->direita != NULL)
                {
                    aux = aux->direita;
                }
                
                raiz->elemento = aux->elemento;
                aux->elemento = elem;
                raiz->esquerda = Remover(raiz->esquerda, elem);
            }
            
        }
        return raiz;
        
    }
    
}
void Imprimir_arvore(arvore *raiz)
{
     if(raiz == NULL)
    {
        printf("NULL");
    } 
    else{
        printf("(");
        Imprimir_arvore(raiz->esquerda);
        printf(")");

        printf(",%d,", raiz->elemento);

        printf("(");
        Imprimir_arvore(raiz->direita);
        printf(")");

    }
     
}
int Consultar(arvore *raiz, int elem)
{
    if (raiz == NULL)
    {
       
        return 0;
    }
    else
    {
        if (raiz->elemento == elem)
        {
            
            return 1;
        }
        else
        {      
            if (raiz->elemento < elem)
            {
                
                return Consultar(raiz->direita, elem);

                
            }
            else{
               return Consultar(raiz->esquerda, elem);
               
            }
            
        }
        
    }
    
}
int main()
{
    arvore *raiz = NULL;

    raiz = Inserir(raiz, 8);
    raiz = Inserir(raiz, 6);
    raiz = Inserir(raiz, 4);
    raiz = Inserir(raiz, 3);
    raiz = Inserir(raiz, 10);
    raiz = Inserir(raiz, 11);
    raiz = Inserir(raiz, 24);

    Imprimir_arvore(raiz);

    int aux = Consultar(raiz, 5);

    if (aux == 1)
    {
        printf("\nYES\n");
    }
    else
    {
        printf("\nNO\n");
    }

    printf("\n\n");

    raiz = Remover(raiz, 10);
    
    Imprimir_arvore(raiz);
    

}