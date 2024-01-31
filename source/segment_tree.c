#include <stdlib.h>
#include <SeGiN/segment_tree.h>

SegmentTree* SGN_constructSegmentTree(int* array, int size)
{
    SegmentTree* segmentTree = (SegmentTree*)malloc(sizeof(SegmentTree));
    segmentTree->tree = (int*)malloc(2*size*sizeof(int));
    segmentTree->size = size;

    int* tree = segmentTree->tree;

    for(int i = 0; i < size; i++)
    {
        tree[size+i] = array[i];
    }

    for(int i = size-1; i > 0; i--)
    {
        tree[i] = tree[2*i] + tree[2*i+1];
    }

    return segmentTree;
}

void SGN_update(SegmentTree* segmentTree, int position, int value)
{
    int* tree = segmentTree->tree;
    int size = segmentTree->size;

    if(position<0||position>size) return;

    position += size;
    tree[position] = value;
    position /= 2;

    while(position>0)
    {
        tree[position] = tree[2*position] + tree[2*position+1];
        position /= 2;
    }
}

int SGN_query(SegmentTree* segmentTree, int left, int right)
{
    int *tree = segmentTree->tree;
    int size = segmentTree->size;

    if(left<0||left>size||right<0||right>size)
    {
        return 0;
    }

    int result = 0;
    left += size;
    right += size;

    while(left<=right)
    {
        if(left%2==1)
        {
            result += tree[left];
            left++;
        }
        if(right%2==0)
        {
            result += tree[right];
            right--;
        }

        left /= 2;
        right /= 2;
    }

    return result;
}