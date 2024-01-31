#include <stdlib.h>
#include <SeGiN/swap.h>
#include <SeGiN/disjoint_set.h>

DisjointSet* SGN_constructDisjointSet(int size)
{
    DisjointSet* disjointSet = (DisjointSet*)malloc(sizeof(DisjointSet));
    disjointSet->parent = (int*)malloc(size*sizeof(int));
    disjointSet->rank = (int*)malloc(size*sizeof(int));
    disjointSet->size = size;

    for(int i = 0; i < size; i++)
    {
        disjointSet->parent[i] = i;
        disjointSet->rank[i] = 0;
    }

    return disjointSet;
}

int SGN_find(DisjointSet* disjointSet, int u)
{
    int *parent = disjointSet->parent;
    int *rank = disjointSet->rank;
    int size = disjointSet->size;

    if(u<0 || u>size) return -1;

    if(parent[u]!=u) parent[u] = SGN_find(disjointSet, parent[u]);
    return parent[u];
}

void SGN_union(DisjointSet* disjointSet, int u, int v)
{
    int *parent = disjointSet->parent;
    int *rank = disjointSet->rank;
    int size = disjointSet->size;

    if(u<0||u>size||v<0||v>size) return;

    u = SGN_find(disjointSet, u);
    v = SGN_find(disjointSet, v);
    if(u==v) return;
    if(rank[u]<rank[v]) SGN_swap(&u, &v, sizeof(int));
    parent[v] = u;
    if(rank[u]==rank[v]) rank[u]++;
}