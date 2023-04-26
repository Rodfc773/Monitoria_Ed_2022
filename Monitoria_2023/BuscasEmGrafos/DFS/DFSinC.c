#include "../Grafos_C/Grafo.c"
#include "../Pilha/Stack.c"
#include <stdio.h>
#include <stdlib.h>

void DFS_initial(struct Graph G, int V){

    int visitados[V];

    for (int i = 0; i < V; i++)
    {
        visitados[i] = 0;
    }

    int vo = 0;

    struct Stack *stack = NULL;

    stack = push(stack, vo);

    


    
}
int main(){


    struct Edge edges[]={

        {0, 1}, {1, 2}, {2, 0}, {2, 1}, {3, 2}, {4, 5}, {5, 4}, {7,2}, {3,0}, {5,2}
    };
    
    int V = sizeof(edges)/sizeof(edges[0]);

    struct Graph *graph = createGraph(edges, V);
    printGraph(graph);

    return 0;
}