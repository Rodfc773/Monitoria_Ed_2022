#include "../Grafos_C/Grafo.c"
#include "../Pilha/Stack.c"
#include <stdio.h>
#include <stdlib.h>

void DFS(int v, struct Graph *G, struct Stack *stack , int visitados[]){

    visitados[v] = 1;

    struct Node* vertice = G->head[v];

    printf("Estamos no vértice: %d e vamos para o vertice: %d\n", v, vertice->dest);
    while (vertice != NULL
    )
    {
        if(!(visitados[vertice->dest])){

            stack = push(stack,vertice->dest);

            DFS(vertice->dest, G, stack, visitados);

            stack = pop(stack);
        }

        vertice = vertice->next;
    }
    
    

}
void DFS_initial(struct Graph *G, int V){

    int visitados[V];

    for (int i = 0; i < V; i++)
    {
        visitados[i] = 0;
    }

    int v = 0;

    struct Stack *stack = NULL;

    stack = push(stack, v);

    DFS(v, G, stack, &visitados[0]);

    stack = pop(stack);

}
int main(){


    struct Edge edges[]={

        {0, 1}, {1, 2}, {2, 0}, {2, 1}, {3, 2}, {4, 5}, {5, 4}, {3, 5}
    };
    
    int V = sizeof(edges)/sizeof(edges[0]);

    struct Graph *graph = createGraph(edges, V);
    printGraph(graph);

    DFS_initial(graph, V);

    return 0;
}