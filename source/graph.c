#include <stdlib.h>
#include <SeGiN/graph.h>

SGN_Edge* SGN_constructEdge(int u, int v)
{
    SGN_Edge* edge = (SGN_Edge*)malloc(sizeof(edge));
    edge->u = u;
    edge->v = v;
    return edge;
}

SGN_Graph* SGN_constructGraph(SGN_Edge** edge, int edgeCount, int size)
{
    SGN_Graph* graph = (SGN_Graph*)malloc(sizeof(SGN_Graph));
    graph->adjacency = (int**)malloc(size*sizeof(int*));
    graph->neighbours = (int*)calloc(size, sizeof(int));
    graph->size = size;

    int** adjacency = graph->adjacency;
    int* neighbours = graph->neighbours;
    int* alreadyAdded = (int*)calloc(size, sizeof(int));

    for(int i = 0; i < edgeCount; i++)
    {
        neighbours[edge[i]->u]++;
        neighbours[edge[i]->v]++;
    } 

    for(int i = 0; i < size; i++) adjacency[i] = (int*)malloc(neighbours[i]*sizeof(int));

    for(int i = 0; i < edgeCount; i++)
    {
        adjacency[edge[i]->u][alreadyAdded[edge[i]->u]++] = edge[i]->v;
        adjacency[edge[i]->v][alreadyAdded[edge[i]->v]++] = edge[i]->u;
    }

    free(alreadyAdded);

    return graph;
}
