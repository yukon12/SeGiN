#ifndef SGN_HEAP
#define SGN_HEAP

typedef struct {
    int *array;
    int size;
    int capacity;
} SGN_Heap;

SGN_Heap* SGN_constructHeap(int* array, int size, int capacity);
void SGN_insertNode(SGN_Heap* heap, int node);
int SGN_deleteNode(SGN_Heap* heap, int index);

#endif
