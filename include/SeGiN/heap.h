#ifndef SGN_HEAP
#define SGN_HEAP

int* SGN_constructHeap(int* array, int size, int capacity);
void SGN_insertNode(int* heap, int size, int capacity, int node);
void SGN_deleteNode(int* heap, int size, int index);

#endif
