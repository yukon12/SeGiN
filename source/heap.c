#include <stdlib.h>
#include <stdio.h>
#include <SeGiN/swap.h>
#include <SeGiN/mathematics.h>
#include <SeGiN/heap.h>

SGN_Heap* SGN_constructHeap(int* array, int size, int capacity)
{
    SGN_Heap* heap = (SGN_Heap*)malloc(sizeof(SGN_Heap));
    heap->array = (int*)malloc(capacity*sizeof(int));
    for(int i = 0; i < size; i++) heap->array[i] = array[i];
    heap->size = size;
    heap->capacity = capacity;

    for(int i = size-1; i >= 0; i--)
    {
        int maximal = i;
        int left = 2*i+1;
        int right = 2*i+2;
        if(left<size&&heap->array[left]>heap->array[maximal]) maximal = left;
        if(right<size&&heap->array[right]>heap->array[maximal]) maximal = right;
        if(maximal!=i) SGN_swap(&heap->array[maximal], &heap->array[i], sizeof(int));
    }

    return heap;
}

void SGN_insertNode(SGN_Heap* heap, int value)
{
    int* array = heap->array;
    int size = heap->size;
    int capacity = heap->capacity;

    if(size==capacity) return;

    heap->size++; 
    size++;
    array[size-1] = value;
    
    int index = size-1;
    while(index>0&&array[index]>array[index/2])
    {
        SGN_swap(&array[index], &array[index/2], sizeof(int));    
        index /= 2;
    }
}

int SGN_deleteNode(SGN_Heap* heap, int index)
{
    int* array = heap->array;
    int size = heap->size;
    SGN_limitMinimum(&index, 0);
    SGN_limitMaximum(&index, size-1);
    
    if(size==0) return 0;

    int value = array[index];
    SGN_swap(&array[index], &array[size-1], sizeof(int));
    heap->size--;

    while(1)
    {
        int maximal = index;
        int left = 2*index+1;
        int right = 2*index+2;
        if(left<heap->size&&array[left]>array[maximal]) maximal = left;
        if(right<heap->size&&array[right]>array[maximal]) maximal = right;
        if(maximal!=index)
        {
            SGN_swap(&array[maximal], &array[index], sizeof(int));
            index = maximal;
        }
        else break;
    }

    return value;
}
