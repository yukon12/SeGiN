#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <SeGiN/swap.h>
#include <SeGiN/mathematics.h>
#include <SeGiN/heap.h>

int* SGN_constructHeap(int* array, int size, int capacity)
{
    int* heap = (int*)malloc(capacity*sizeof(int));
    for(int i = 0; i < size; i++) heap[i] = array[i];

    for(int i = size-1; i >= 0; i--)
    {
        int maximal = i;
        int left = 2*i+1;
        int right = 2*i+2;
        if(left<size&&heap[left]>heap[maximal]) maximal = left;
        if(right<size&&heap[right]>heap[maximal]) maximal = right;
        if(maximal!=i) SGN_swapIntegers(&heap[maximal], &heap[i]);
    }

    return heap;
}

void SGN_insertNode(int* heap, int size, int capacity, int value)
{
    if(size==capacity) return;
    size++;
    heap[size-1] = value;
    
    int index = size-1;
    while(index>0&&heap[index]>heap[index/2])
    {
        SGN_swapIntegers(&heap[index], &heap[index/2]);    
        index /= 2;
    }
}

void SGN_deleteNode(int* heap, int size, int index)
{
    assert(index>=0&&index<size);

    SGN_swapIntegers(&heap[index], &heap[size-1]);
    size--;

    while(1)
    {
        int maximal = index;
        int left = 2*index+1;
        int right = 2*index+2;
        if(left<size&&heap[left]>heap[maximal]) maximal = left;
        if(right<size&&heap[right]>heap[maximal]) maximal = right;
        if(maximal!=index)
        {
            SGN_swapIntegers(&heap[maximal], &heap[index]); 
            index = maximal;
        }
        else break;
    }
}
