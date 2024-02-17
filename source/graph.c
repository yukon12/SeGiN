#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#include <SeGiN/graph.h>

int** SGN_constructGraph(int size)
{
    int** graph = (int**)malloc(size*sizeof(int*));
    for(int u = 0; u < size; u++)
    {
        graph[u] = (int*)malloc(size*sizeof(int));
        for(int v = 0; v < size; v++) graph[u][v] = INT_MAX;
    }
    return graph;
}

void SGN_addUndirectedEdge(int** graph, int size, int u, int v, int weight)
{
    assert(u>=0&&u<size&&v>=0&&v<size);
    graph[u][v] = weight;
    graph[v][u] = weight;
}

void SGN_addDirectedEdge(int** graph, int size, int u, int v, int weight)
{
    assert(u>=0&&u<size&&v>=0&&v<size);
    graph[u][v] = weight;
}
