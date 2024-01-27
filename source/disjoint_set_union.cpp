#include <disjoint_set_union.hpp>

DisjointSetUnion::DisjointSetUnion(int n)
{
    parent = std::vector<int>(n);
    size = std::vector<int>(n);
    for(int i = 0; i < n; i++)
    {
        parent[i] = i;
        size[i] = 1;
    }
}

int DisjointSetUnion::_find(int x)
{
    if(parent[x]!=x) parent[x] = _find(parent[x]);
    return parent[x];
}

void DisjointSetUnion::_union(int x, int y)
{
    x = _find(x);
    y = _find(y);
    if(x==y) return;
    if(size[x]<size[y]) std::swap(x, y);
    parent[y] = x;
    size[x] += size[y]; 
}