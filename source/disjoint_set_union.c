#include <stdlib.h>
#include <assert.h>
#include <SeGiN/swap.h>
#include <SeGiN/disjoint_set_union.h>

int* SGN_constructDisjointSetUnion(int size)
{
    int* dsu = (int*)malloc(size*sizeof(int));
    for(int i = 0; i < size; i++) dsu[i] = i;
    return dsu;
}

int SGN_findDSU(int* dsu, int size, int u)
{
    assert(u>=0&&u<size);
    int v = u;
    while(dsu[v]!=v) v = dsu[v];
    while(dsu[u]!=u)
    {
        dsu[u] = v;
        u = dsu[u];
    }
    return v;
}

void SGN_unionDSU(int* dsu, int* rank, int size, int u, int v)
{
    assert(u>=0&&u<size&&v>=0&&v<size);
    u = SGN_findDSU(dsu, size, u);
    v = SGN_findDSU(dsu, size, v);
    if(u==v) return;
    if(rank[u]<rank[v]) SGN_swapIntegers(&u, &v);
    dsu[v] = u;
    if(rank[u]==rank[v]) rank[u]++;
}
