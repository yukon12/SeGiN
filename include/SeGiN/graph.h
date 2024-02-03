#ifndef SGN_GRAPH
#define SGN_GRAPH

typedef struct
{
    int u;
    int v;
} SGN_Edge;

SGN_Edge* SGN_constructEdge(int u, int v);

typedef struct
{
    int** adjacency;
    int* neighbours;
    int size;
} SGN_Graph;

SGN_Graph* SGN_constructGraph(SGN_Edge** edge, int edgeCount, int size);

#endif
