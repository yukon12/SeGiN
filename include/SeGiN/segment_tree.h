#ifndef SGN_SEGMENT_TREE
#define SGN_SEGMENT_TREE

typedef struct
{
    int *tree;
    int size;
} SGN_SegmentTree;

SGN_SegmentTree* SGN_constructSegmentTree(int* array, int size);
void SGN_update(SGN_SegmentTree* segmentTree, int position, int value);
int SGN_query(SGN_SegmentTree* segmentTree, int left, int right);

#endif