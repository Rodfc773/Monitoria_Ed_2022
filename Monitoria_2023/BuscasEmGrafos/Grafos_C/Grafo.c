#include "Grafo.h"
#include <stdio.h>
#include <stdlib.h>

struct Graph* createGraph(struct Edge edges[], int n)
{
    // aloca armazenamento para a estrutura de dados do gráfico
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
 
    // inicializa o ponteiro de cabeça para todos os vértices
    for (int i = 0; i < N; i++) {
        graph->head[i] = NULL;
    }
 
    // adiciona arestas ao grafo direcionado uma a uma
    for (int i = 0; i < n; i++)
    {
        // obtém o vértice de origem e destino
        int src = edges[i].src;
        int dest = edges[i].dest;
 
        // aloca um novo nó da lista de adjacências de src para dest
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->dest = dest;
 
        // aponta novo nó para a cabeça atual
        newNode->next = graph->head[src];
 
        // aponta o ponteiro principal para o novo nó
        graph->head[src] = newNode;

        // Aloca um novo no para fazer a ligação dest -> src

        newNode = (struct Node*)malloc(sizeof(struct Node));

        newNode->dest = dest;

        graph->head[dest] = newNode;
    }
 
    return graph;
}
void printGraph(struct Graph* graph)
{
    for (int i = 0; i < N; i++)
    {
        // imprime o vértice atual e todos os seus vizinhos
        struct Node* ptr = graph->head[i];
        while (ptr != NULL)
        {
            printf("(%d —> %d)\t", i, ptr->dest);
            ptr = ptr->next;
        }
 
        printf("\n");
    }
}