#ifndef SGN_WEIGHTED_GRAPH
#define SGN_WEIGHTED_GRAPH

typedef struct
{
    int u;
    int v;
    int weight;
} SGN_WeightedEdge;

SGN_WeightedEdge* SGN_constructWeightedEdge(int u, int v, int weight);

typedef struct
{
    int** adjacency;
    int** edgeWeight;
    int* neighbours;
    int size;
} SGN_WeightedGraph;

SGN_WeightedGraph* SGN_constructWeightedGraph(SGN_WeightedEdge** weightedEdge, int edgeCount, int size);

#endif
