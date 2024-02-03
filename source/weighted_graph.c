#include <stdlib.h>
#include <SeGiN/weighted_graph.h>

SGN_WeightedEdge* SGN_constructWeightedEdge(int u, int v, int weight)
{
    SGN_WeightedEdge* weightedEdge = (SGN_WeightedEdge*)malloc(sizeof(weightedEdge));
    weightedEdge->u = u;
    weightedEdge->v = v;
    weightedEdge->weight = weight;
    return weightedEdge;
}

SGN_WeightedGraph* SGN_constructWeightedGraph(SGN_WeightedEdge** weightedEdge, int edgeCount, int size)
{
    SGN_WeightedGraph* weightedGraph = (SGN_WeightedGraph*)malloc(sizeof(SGN_WeightedGraph));
    weightedGraph->adjacency = (int**)malloc(size*sizeof(int*));
    weightedGraph->edgeWeight = (int**)malloc(size*sizeof(int*));
    weightedGraph->neighbours = (int*)calloc(size, sizeof(int));
    weightedGraph->size = size;

    int** adjacency = weightedGraph->adjacency;
    int** edgeWeight = weightedGraph->edgeWeight;
    int* neighbours = weightedGraph->neighbours;
    int* alreadyAdded = (int*)calloc(size, sizeof(int));

    for(int i = 0; i < edgeCount; i++)
    {
        neighbours[weightedEdge[i]->u]++;
        neighbours[weightedEdge[i]->v]++;
    } 

    for(int i = 0; i < size; i++) adjacency[i] = (int*)malloc(neighbours[i]*sizeof(int));
    for(int i = 0; i < size; i++) edgeWeight[i] = (int*)malloc(neighbours[i]*sizeof(int));

    for(int i = 0; i < edgeCount; i++)
    {
        adjacency[weightedEdge[i]->u][alreadyAdded[weightedEdge[i]->u]] = weightedEdge[i]->v;
        adjacency[weightedEdge[i]->v][alreadyAdded[weightedEdge[i]->v]] = weightedEdge[i]->u;
        edgeWeight[weightedEdge[i]->u][alreadyAdded[weightedEdge[i]->u]++] = weightedEdge[i]->weight;
        edgeWeight[weightedEdge[i]->v][alreadyAdded[weightedEdge[i]->v]++] = weightedEdge[i]->weight;
    }

    free(alreadyAdded);

    return weightedGraph;
}
