#define N 10
struct Graph
{
    // Um array de ponteiros para Node para representar uma lista de adjacências
    struct Node* head[N];
};
struct Node
{
    int dest;
    struct Node* next;
};
struct Edge {
    int src, dest;
};
struct Graph* createGraph(struct Edge edges[], int n);
void printGraph(struct Graph* graph);