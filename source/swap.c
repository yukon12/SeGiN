#include <stdlib.h>
#include <string.h>
#include <SeGiN/swap.h>

void SGN_swap(void* left, void *right, size_t size)
{
    void* temporary = (void*)malloc(size);
    memcpy(temporary, left, size);
    memcpy(left, right, size);
    memcpy(right, temporary, size);
    free(temporary);
}