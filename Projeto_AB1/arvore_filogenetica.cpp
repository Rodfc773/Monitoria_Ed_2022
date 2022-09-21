#include <iostream>
#include <stdlib.h>

struct  no
{
    int especie;
    
    no *rigth;
    no *left;
    int filogenia[];

};

no *Arvore(no *raiz, int especie, int &i, int matriz[][7]);
void Filogenetica(no *especie, int matriz[][7], int i);

bool Filamentos_c1(int c1_especie1, int c1_especie2) 
//Função para verificar se a caracteristica c1 da especie 1 é igual ou a da especie 2
{

    if(c1_especie1 != c1_especie2) return true;

    return false;
}
bool Filamentos_c2(int c2_especie1, int c2_especie2){

    if(c2_especie1 != c2_especie2) return true;

    return false;
}

int main(){

    no *raiz =  NULL;

    int matriz[7][7] = {
        {1, 0 ,1 ,0 ,0 ,1 ,0},
        {0, 1, 1, 0, 0, 1, 0},
        {1, 0, 0, 1, 0, 1, 0},
        {0, 1, 0, 0, 1, 1, 0},
        {1, 0, 0, 1, 0, 0, 1},
        {0, 1, 0, 1, 0, 0, 1},
        {1, 0, 0, 1, 0, 1, 0}
    };

    


    return 0;
}

void Filogenetica(no *especie, int matriz[][7], int i){

    for (int j = 0; j < 7; j++)
    {
        especie->filogenia[j] = matriz[i][j];
    }
    
}
/*no *Arvore(no *raiz, int especie, int &i, int matriz[][7]){

    if(raiz == NULL){

        raiz = (no*)malloc(sizeof(no) * 30);

        raiz->especie = especie;
        raiz->left = NULL;
        raiz->rigth = NULL;

        return raiz;
    }
    else{

        if(raiz->filogenia[i]){


        }
    }
    return raiz;
}*/
