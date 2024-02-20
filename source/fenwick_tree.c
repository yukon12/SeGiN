#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <SeGiN/fenwick_tree.h>

int* SGN_constructFenwickTree(int* array, int size)
{
    int* tree = (int*)calloc(size, sizeof(int));
    for(int i = 0; i < size; i++) SGN_updateFT(tree, size, i, array[i]);
    return tree;
}

void SGN_updateFT(int* tree, int size, int position, int value)
{
    assert(position>=0&&position<size);

    while(position<size)
    {
        tree[position] += value;
        position = position|(position+1);
    }
}

int SGN_queryFT(int* tree, int size, int left, int right)
{
    assert(left>=0&&left<size&&right>=0&&right<size);

    left--;
    int subtract = 0;
    while(left>=0)
    {
        subtract += tree[left];
        left = (left&(left+1))-1;
    }

    int add = 0;
    while(right>=0)
    {
        add += tree[right];
        right = (right&(right+1))-1;
    }

    return add-subtract;
}
