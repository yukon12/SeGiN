#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <SeGiN/mathematics.h>
#include <SeGiN/dijkstra.h>

int* SGN_shortestPathToAll(SGN_WeightedGraph* weightedGraph, int source)
{
    int** adjacency = weightedGraph->adjacency;
    int** edgeWeight = weightedGraph->edgeWeight;
    int* neighbours = weightedGraph->neighbours;
    int size = weightedGraph->size;

    SGN_limitMinimum(&source, 0);
    SGN_limitMaximum(&source, size-1);
    
    int* distance = (int*)malloc(size*sizeof(int));    
    for(int i = 0; i < size; i++) distance[i] = INT_MAX;
    distance[source] = 0;
    bool* visited = (bool*)calloc(size, sizeof(bool));

    for(int i = 0; i < size; i++)
    {
        int minimalDistance = INT_MAX;
        int u = -1;
        for(int j = 0; j < size; j++)
        {
            if(!visited[j]&&distance[j]<minimalDistance)
            {
                minimalDistance = distance[j];
                u = j;
            }
        }

        visited[u] = true;

        for(int j = 0; j < neighbours[u]; j++)
        {
            int v = adjacency[u][j];
            int weight = edgeWeight[u][j];

            SGN_limitMaximum(&distance[v], distance[u]+weight);
        }
    }

    return distance;
}

int SGN_shortestPath(SGN_WeightedGraph* weightedGraph, int source, int destination)
{
    SGN_limitMinimum(&destination, 0);
    SGN_limitMaximum(&destination, weightedGraph->size-1);
    int* distance = SGN_shortestPathToAll(weightedGraph, source);
    int answer = distance[destination];
    free(distance);
    return answer;
}
