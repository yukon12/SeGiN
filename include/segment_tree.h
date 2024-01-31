#include <stdlib.h>
#ifndef SGN_SEGMENT_TREE
#define SGN_SEGMENT_TREE

typedef struct
{
    int *tree;
    int size;
} SegmentTree;

SegmentTree* SGN_constructSegmentTree(int n);
void SGN_update(SegmentTree* segmentTree, int p, int v);
int SGN_query(SegmentTree* SegmentTree, int l, int r);

#endif