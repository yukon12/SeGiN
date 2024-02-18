#ifndef SGN_SEGMENT_TREE
#define SGN_SEGMENT_TREE

int* SGN_constructSegmentTree(int* array, int size);
void SGN_updateST(int* tree, int size, int position, int value);
int SGN_queryST(int* tree, int size, int left, int right);

#endif
