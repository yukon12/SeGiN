#include <disjoint_set.h>

DisjointSet* SGN_constructDisjointSet(int n)
{
    DisjointSet* object = (DisjointSet*)malloc(sizeof(DisjointSet));
    object->parent = malloc(n*sizeof(int));
    object->rank = malloc(n*sizeof(int));
    object->size = n;

    for(int i = 0; i < n; i++)
    {
        object->parent[i] = i;
        object->rank[i] = 1;
    }

    return object;
}

int SGN_find(DisjointSet* disjointSet, int u)
{
    if(u<0 || u>disjointSet->size)
    {
        return -1;
    }

    if(disjointSet->parent[u]!=u) disjointSet->parent[u] = SGN_find(disjointSet, disjointSet->parent[u]);
    return disjointSet->parent[u];
}

void SGN_union(DisjointSet* disjointSet, int u, int v)
{
    u = SGN_find(disjointSet, u);
    v = SGN_find(disjointSet, v);
    if(u==v)
    {
        return;
    }
    if(disjointSet->rank[u]<disjointSet->rank[v])
    {
        int temp = u;
        u = v;
        v = temp;
    }
    disjointSet->parent[v] = u;
    disjointSet->rank[u] += disjointSet->rank[v];
}