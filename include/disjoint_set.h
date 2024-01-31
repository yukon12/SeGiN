#include <stdlib.h>
#ifndef SGN_DISJOINT_SET
#define SGN_DISJOINT_SET

typedef struct
{
    int *parent;
    int *rank;
    int size;
} DisjointSet;

DisjointSet* SGN_constructDisjointSet(int n);
int SGN_find(DisjointSet* disjointSet, int u);
void SGN_union(DisjointSet* disjointSet, int u, int v);

#endif