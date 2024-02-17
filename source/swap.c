#include <SeGiN/swap.h>

void SGN_swapIntegers(int* left, int *right)
{
    int temporary = *left;
    *left = *right;
    *right = temporary;
}
