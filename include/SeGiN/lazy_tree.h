#ifndef SGN_LAZY_TREE
#define SGN_LAZY_TREE

int* SGN_constructLazyTree(int* array, int size, int* treeSize);
int SGN_queryLT(int* tree, int* lazy, int size, int left, int right);
void SGN_updateLT(int* tree, int* lazy, int size, int left, int right, int value);

#endif
