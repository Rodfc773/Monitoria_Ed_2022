#include <iostream>
#include <vector>

struct Edges{

    int u, v, weight;
};

typedef std::pair<int,int> Pair;

class Graph
{
public:
    //Vetor de vetores que representam a lista de adjacência
    std::vector<std::vector<Pair>> adjList;
    //Construtor do grafo

    Graph(std::vector<Edges> const &edges, int n);
};

void printGraph(Graph const &graph, int n);

