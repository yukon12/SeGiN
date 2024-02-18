#include <stdlib.h>
#include <assert.h>
#include <SeGiN/lazy_tree.h>

void constructUtility(int* array, int* tree, int node, int spanLeft, int spanRight)
{
    if(spanLeft==spanRight)
    {
        tree[node] = array[spanLeft];
        return;
    }

    int spanMiddle = (spanLeft+spanRight)/2;
    constructUtility(array, tree, 2*node+1, spanLeft, spanMiddle);
    constructUtility(array, tree, 2*node+2, spanMiddle+1, spanRight);
    tree[node] = tree[2*node+1]+tree[2*node+2];
}

int* SGN_constructLazyTree(int* array, int size, int* treeSize)
{
    int maxSize = 1;
    while(maxSize<size) maxSize <<= 1;
    maxSize <<= 1;
    *treeSize = maxSize;
    int* tree = (int*)malloc(maxSize*sizeof(int));
    constructUtility(array, tree, 0, 0, size-1);
    return tree;
}

int queryUtility(int* tree, int* lazy, int size, int node, int spanLeft, int spanRight, int queryLeft, int queryRight)
{
    if(lazy[node]!=0)
    {
        tree[node] += (spanRight-spanLeft+1)*lazy[node];
        if(spanLeft!=spanRight)
        {
            lazy[2*node+1] += lazy[node];
            lazy[2*node+2] += lazy[node];
        }
        lazy[node] = 0;
    }

    if(spanLeft>spanRight||spanRight<queryLeft||spanLeft>queryRight) return 0;

    if(spanLeft>=queryLeft&&spanRight<=queryRight) return tree[node];

    int spanMiddle = (spanLeft+spanRight)/2;
    int result = 0;
    result += queryUtility(tree, lazy, size, 2*node+1, spanLeft, spanMiddle, queryLeft, queryRight);
    result += queryUtility(tree, lazy, size, 2*node+2, spanMiddle+1, spanRight, queryLeft, queryRight);
    return result;
}

int SGN_queryLT(int* tree, int* lazy, int size, int left, int right)
{
    assert(left>=0&&left<size&&right>=0&&right<size);
    return queryUtility(tree, lazy, size, 0, 0, size-1, left, right);
}

void updateUtility(int* tree, int* lazy, int size, int node, int spanLeft, int spanRight, int updateLeft, int updateRight, int value)
{
    if(lazy[node]!=0)
    {
        tree[node] += (spanRight-spanLeft+1)*lazy[node];
        if(spanLeft!=spanRight)
        {
            lazy[2*node+1] += lazy[node];
            lazy[2*node+2] += lazy[node];
        }
        lazy[node] = 0;
    }

    if(spanLeft>spanRight||spanRight<updateLeft||spanLeft>updateRight) return;

    if(spanLeft>=updateLeft&&spanRight<=updateRight)
    {
        tree[node] += (spanRight-spanLeft+1)*value;
        if(spanLeft!=spanRight)
        {
            lazy[2*node+1] += value;
            lazy[2*node+2] += value;
        }
        return;
    }

    int spanMiddle = (spanLeft+spanRight)/2;
    updateUtility(tree, lazy, size, 2*node+1, spanLeft, spanMiddle, updateLeft, updateRight, value);
    updateUtility(tree, lazy, size, 2*node+2, spanMiddle+1, spanRight, updateLeft, updateRight, value);
    tree[node] = tree[2*node+1]+tree[2*node+2];
}

void SGN_updateLT(int* tree, int* lazy, int size, int left, int right, int value)
{
    assert(left>=0&&left<size&&right>=0&&right<size);
    updateUtility(tree, lazy, size, 0, 0, size-1, left, right, value);
}
