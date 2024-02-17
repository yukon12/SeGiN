#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <assert.h>
#include <SeGiN/mathematics.h>
#include <SeGiN/dijkstra.h>

int* SGN_dijkstra(int** graph, int size, int source)
{
    int* distance = (int*)malloc(size*sizeof(int));    
    for(int i = 0; i < size; i++) distance[i] = INT_MAX;
    assert(source>=0&&source<size);
    distance[source] = 0;
    bool* visited = (bool*)calloc(size, sizeof(bool));

    for(int i = 0; i < size; i++)
    {
        int u = INT_MAX;
        for(int j = 0; j < size; j++)
        {
            if(!visited[j]&&(u==INT_MAX||distance[j]<distance[u])) u = j;
        }

        visited[u] = true;

        for(int v = 0; v < size; v++)
        {
            if(graph[u][v]!=INT_MAX) distance[v] = SGN_minimum(distance[v], distance[u]+graph[u][v]);
        }
    }

    return distance;
}
