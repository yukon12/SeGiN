#ifndef SGN_DIJKSTRA
#define SGN_DIJKSTRA
#include "weighted_graph.h"

int* SGN_shortestPathToAll(SGN_WeightedGraph* weightedGraph, int source);
int SGN_shortestPath(SGN_WeightedGraph* weightedGraph, int source, int destination);

#endif
