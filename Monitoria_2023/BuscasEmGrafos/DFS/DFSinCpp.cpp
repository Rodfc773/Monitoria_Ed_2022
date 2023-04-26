#include <iostream>
#include "../Grafos_C++/Grafo.cpp"
#include <stack>

void DFS(int v, Graph const &graph , std::vector<bool> &visitados){

    visitados[v] = true;

    for (int i = 0; i < graph.adjList[v].size(); i++)
    {
        if(!(visitados[graph.adjList[v][i].second])) DFS(graph.adjList[v][i].second, graph, visitados);
    }

}
void chamarDFS(Graph G,int v){

    //Obs: implementar com pilha depois
    //std::stack<int> pilha;

    std::vector<bool> visitados;

    visitados.resize(v);

    for (int i = 0; i < visitados.size(); i++)
    {
        visitados[i] = false;
    }

    int vo = rand() * G.adjList.size();

    //pilha.push(vo);



}
int main(){

    std::vector<Edges> edges = {

        // (x, y, w) —> aresta de `x` a `y` tendo peso `w`
        {0, 1, 6}, {1, 2, 7}, {2, 0, 5}, {2, 5, 4}, {3, 2, 10}, {5, 4, 1}, {4, 1, 3}
    };

    int V = edges.size()+1;

    Graph graph(edges, V);

    printGraph(graph, V);
    return 0;
}