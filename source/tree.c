#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <assert.h>
#include <SeGiN/tree.h>

static bool dfsCheck(int u, int parent, int** graph, int size, bool* visited)
{
    bool valid = true;
    if(visited[u]) return false;
    visited[u] = true; 
    for(int v = 0; v < size; v++)
    {
        if(graph[u][v]!=INT_MAX&&v!=parent)
        {
            valid = valid&dfsCheck(v, u, graph, size, visited);
        }
    }
    return valid;
}

int SGN_isTree(int** graph, int size)
{
    assert(size>0);
    bool valid = true;
    for(int i = 0; i < size; i++)
    {
        if(graph[i][i]!=INT_MAX)
        {
            valid = false;
            break;
        }
        for(int j = i+1; j < size; j++)
        {
            if(graph[i][j]!=graph[j][i])
            {
                valid = false;
                break;
            }
        }
        if(!valid) break;
    }

    if(!valid) return 0;

    bool* visited = (bool*)calloc(size, sizeof(bool));
    valid = dfsCheck(0, -1, graph, size, visited);
    return (int)valid;
}

static void dfsConstruct(int u, int parent, int** graph, int size, int* tree)
{
    tree[u] = parent;
    for(int v = 0; v < size; v++)
    {
        if(graph[u][v]!=INT_MAX&&v!=parent)
        {
            dfsConstruct(v, u, graph, size, tree);
        }
    }
}

int* SGN_constructTree(int** graph, int size, int source)
{
    assert(size>0);
    assert(source>=0&&source<size);
    int* tree = (int*)malloc(size*sizeof(int));
    dfsConstruct(source, -1, graph, size, tree);
    return tree;
}
