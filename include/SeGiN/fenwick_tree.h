#ifndef SGN_FENWICK_TREE
#define SGN_FENWICK_TREE

int* SGN_constructFenwickTree(int* array, int size);
void SGN_updateFT(int* tree, int size, int position, int value);
int SGN_queryFT(int* tree, int size, int left, int right);

#endif
