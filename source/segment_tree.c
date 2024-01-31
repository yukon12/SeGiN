#include <segment_tree.h>

SegmentTree* SGN_constructSegmentTree(int n)
{
    SegmentTree* object = (SegmentTree*)malloc(sizeof(SegmentTree));
    object->tree = (int*)calloc(2*n, sizeof(int));
    object->size = n;
}

void SGN_update(SegmentTree* segmentTree, int p, int v)
{
    if(p<0 || p>segmentTree->size)
    {
        return;
    }

    p += segmentTree->size;
    segmentTree->tree[p] = v;
    p /= 2;

    while(p>0)
    {
        segmentTree->tree[p] = segmentTree->tree[2*p] + segmentTree->tree[2*p+1];
        p /= 2;
    }
}

int SGN_query(SegmentTree* segmentTree, int l, int r)
{
    if(l<0||l>segmentTree->size||r<0||r>segmentTree->size)
    {
        return 0;
    }

    int result = 0;
    l += segmentTree->size;
    r += segmentTree->size;

    while(l<=r)
    {
        if(l%2==1)
        {
            result += segmentTree->tree[l];
            l++;
        }
        if(r%2==0)
        {
            result += segmentTree->tree[r];
            r--;
        }

        l /= 2;
        r /= 2;
    }

    return result;
}