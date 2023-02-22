#include<stdio.h>
#include<stdlib.h>

typedef struct nodeArv{
    int data;
    struct nodeArv *left;
    struct nodeArv *right;

}nodeArv;

//node = raiz
nodeArv *create()
{
    return NULL;
}

nodeArv *Delete(nodeArv *node, int number)
{
    nodeArv *aux1, *aux2;

    if(node == NULL)
    {
        return NULL;
    }

    if (number < node->data){
        node->left =  Delete(node->left, number);
    }
    else if(number > node->data){
        node->right =  Delete(node->right, number);
    }
    else{       //entra na condicao do numbero ser igual ao no
        
        if(node->left == NULL && node->right == NULL){
            free(node);
            return NULL;
        }
        else if(node->right == NULL){
            aux1 = node;
            node = node->left;
            free(aux1);
        }
        else if(node->left==NULL){
            aux1 = node;
            node = node->right;
            free(aux1);
        } // tem dois filhos >>
        else{
            aux2 = node->left;
            while (node->right != NULL){
                node = node->right;
            }
            node->data = aux2->data;

            aux2->data = number;
            node->left = Delete(node->left, number);

        }


    }


    return node;
}

void printTree(nodeArv *node)
{
    if(node != NULL){
        printf("(");
        printTree(node->left);
        printf("(%d)", node->data);
        printTree(node->right);
        printf(")");
    }
    else printf("( )");
}


int Consultar(nodeArv *raiz, int elem)
{
    if (raiz == NULL)
    {
        return 0;
    }
    else
    {
        if (raiz->data == elem)
        {
            return 1;
        }
        else
        {
            if (raiz->data < elem)
            {
                return Consultar(raiz->right, elem);

            }
            else{
               return Consultar(raiz->left, elem);
            }
        }
    }
}

nodeArv *Insert(nodeArv *node, int value)
{
    //se estiver vazia vai inserir
    if(node == NULL)
    {
        node = (nodeArv*)malloc(sizeof(nodeArv));
        node->data = value; 
        node->left = NULL;
        node->right = NULL;   
    }
    else{
        //se o valor for menor que a raiz vai pra esquerda
        if(node->data > value){
            //o valor do no a esquerda recebe a funçao de inserir
            node->left = Insert(node->left, value);
        }
        else if(node->data < value){
            //o valor do no a direita recebe a funçao de inserir
            node->right = Insert (node->right, value);
        }


    }
    return node;

}
int main()
{
    nodeArv *root = NULL;
    int element1=8,element2=6,element3=4,element4=10,element5=11,element6=24,element7=3;

    //root = create();

    root = Insert(root, element1);
    root = Insert(root, element2);
    root = Insert(root, element3);
    root = Insert(root, element4);
    root = Insert(root, element5);
    root = Insert(root, element6);
    root = Insert(root, element7);

    printTree(root);

    int number = 5;
    printf("\n");
    int valor = Consultar(root, number);
    printf("\n");

    if(valor)printf("Numero encontrado\n");
    else printf("Numero  nao encontrado");

    int number2 = 24;
    valor = Consultar(root, number2);

    if(valor)printf("Numero encontrado\n");
    else printf("numero nao encontrado");

    printf("\n");

    root = Delete(root, 10);

    printTree(root);

}