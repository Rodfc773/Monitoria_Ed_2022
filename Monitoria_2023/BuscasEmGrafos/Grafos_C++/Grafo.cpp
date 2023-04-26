#include "Grafo.h"
#include <iostream>

Graph::Graph(std::vector<Edges> const &edges, int n){

    //redimensionando a lista de adjacência

    adjList.resize(n);

    //Adiciona as arestas nos respectivos vértices adjacentes
    for (auto &edge:edges)
    {
        adjList[edge.u].push_back(std::make_pair(edge.v,edge.weight));
        //adjList[edge.v].push_back(std::make_pair(edge.u,edge.weight));
    }
    
}
void printGraph(Graph const &graph, int n)
{
    for (int i = 0; i < n; i++)
    {
        // Função para imprimir todos os vértices vizinhos de um determinado vértice
        for (Pair v: graph.adjList[i]) {
            std::cout << "(Src: " << i << ", Dest:" << v.first << ", Peso:" << v.second << ") ";
        }
        std::cout << std::endl;
    }
}
