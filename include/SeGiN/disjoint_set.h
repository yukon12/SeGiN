#ifndef SGN_DISJOINT_SET
#define SGN_DISJOINT_SET

typedef struct
{
    int *parent;
    int *rank;
    int size;
} SGN_DisjointSet;

SGN_DisjointSet* SGN_constructDisjointSet(int size);
int SGN_find(SGN_DisjointSet* disjointSet, int u);
void SGN_union(SGN_DisjointSet* disjointSet, int u, int v);

#endif