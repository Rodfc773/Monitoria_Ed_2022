#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Arvore
{
    char elem[10];
    struct Arvore *esquerda;
    struct Arvore *direita; 
}Arvore;

int funcao_comparacao(int j, int k, char *array[][10],int semelhanca, int tam)
{
    for(int i=0; i<tam; i++){

        if(array[i][j] == array[i][k]){
            
            semelhanca++;}
    }
    return semelhanca;
}


void inserir(Arvore **raiz, int i, int j, int k, char animal[], char *matriz_car[][10]){
    if (*raiz == NULL){
        *raiz = malloc (sizeof (Arvore)); 
        strcpy((*raiz)->elem, &animal[i]);
        k = i;
        printf("\nk = %d\n", k);
        (*raiz)->esquerda = NULL;
        (*raiz)->direita = NULL;
       
    } else {
        int semelhanca;
        i++;
        semelhanca = funcao_comparacao(j, k, matriz_car, 0, 4);
        printf("\nsemelhanca = %d\n", semelhanca);
        if (semelhanca <= 2){
            printf("animal esta a esquerda");
            inserir(&((*raiz)->esquerda), i, j, k, animal, matriz_car);
        } else if(semelhanca > 2) {
            printf("animal esta a direita");
            inserir(&((*raiz)->direita), i, j, k, animal, matriz_car);
        } printf("\n\n k=%d\n", k);
    }
}
void imprimir(Arvore *raiz){
    if(raiz){
        printf("\n%s\n", raiz->elem);
        imprimir(raiz->esquerda);
        imprimir(raiz->direita);
    }
}


int main(){
    Arvore *raiz = NULL;
    int op, i, j, k;
    i = 0;
    k = 0;
    j = 0;
    char matriz_ani[10], *matriz_car[4][10];
    printf("\nadcione o Animal ancestral:\n");
    scanf("%s", &matriz_ani[i]);
    printf("\nadcione as caracteristicas do animal ancestral:\n");
   
    for (int j = 0; j < 4; j++){
        char array_car[10];
        scanf("%s", array_car);
        matriz_car[j][k] = array_car;
        
    }
    inserir(&raiz, 0, 0, 0, matriz_ani, matriz_car);
    
    op = 1;

    while(op != 0 && i < 10){
        printf("para sair digite 0\npara adcionar animais digite 1\npara imprimir a arvore digite 2:\n");
        scanf("%d", &op);
        switch(op){

            case 0: 
                
                break;

            case 1:

            i++;
            j++;
            k++;
            printf("\ndigite seu animal\n");
            scanf("%s", &matriz_ani[i]);
            printf("\ndigite as caracteristicas do animal:\n");
            for (int x = 0; x < 4; x++){
                char array_car[10];
                scanf("%s", array_car);
                matriz_car[x][k] = array_car;
            }
            inserir(&raiz, i, j, k, matriz_ani, matriz_car);

            case 2:

            imprimir(raiz);
            break;

        }


        
    }



}