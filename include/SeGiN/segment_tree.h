#ifndef SGN_SEGMENT_TREE
#define SGN_SEGMENT_TREE

int* SGN_constructSegmentTree(int* array, int size);
void SGN_updateST(int* segmentTree, int size, int position, int value);
int SGN_queryST(int* segmentTree, int size, int left, int right);

#endif
