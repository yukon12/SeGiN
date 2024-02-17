#ifndef SGN_GRAPH
#define SGN_GRAPH

int** SGN_constructGraph(int size);
void SGN_addUndirectedEdge(int** graph, int size, int u, int v, int weight);
void SGN_addDirectedEdge(int** graph, int size, int u, int v, int weight);

#endif
