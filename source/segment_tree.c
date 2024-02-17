#include <stdlib.h>
#include <assert.h>
#include <SeGiN/segment_tree.h>

int* SGN_constructSegmentTree(int* array, int size)
{
    int* tree = (int*)malloc(2*size*sizeof(int));

    for(int i = 0; i < size; i++)
    {
        tree[size+i] = array[i];
    }

    for(int i = size-1; i > 0; i--)
    {
        tree[i] = tree[2*i] + tree[2*i+1];
    }

    return tree;
}

void SGN_updateST(int* tree, int size, int position, int value)
{
    assert(position>=0&&position<size);
    position += size;
    tree[position] = value;
    position /= 2;

    while(position>0)
    {
        tree[position] = tree[2*position] + tree[2*position+1];
        position /= 2;
    }
}

int SGN_queryST(int* tree, int size, int left, int right)
{
    assert(left>=0&&left<size&&right>=0&&right<size);
    
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
