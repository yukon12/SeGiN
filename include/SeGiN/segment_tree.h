#ifndef SGN_SEGMENT_TREE
#define SGN_SEGMENT_TREE

typedef struct
{
    int *tree;
    int size;
} SegmentTree;

SegmentTree* SGN_constructSegmentTree(int* array, int size);
void SGN_update(SegmentTree* segmentTree, int position, int value);
int SGN_query(SegmentTree* segmentTree, int left, int right);

#endif