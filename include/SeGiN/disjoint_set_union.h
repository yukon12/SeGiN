#ifndef SGN_DISJOINT_SET_UNION
#define SGN_DISJOINT_SET_UNION

int* SGN_constructDisjointSetUnion(int size);
int SGN_findDSU(int* dsu, int size, int u);
void SGN_unionDSU(int* dsu, int* rank, int size, int u, int v);

#endif
