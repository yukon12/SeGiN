#ifndef SGN_PREFIX_SUM
#define SGN_PREFIX_SUM

typedef struct
{
    int* sum;
    int size;
} SGN_PrefixSum;

SGN_PrefixSum* SGN_constructPrefixSum(int* array, int size);
int SGN_rangeSum(SGN_PrefixSum* prefixSum, int left, int right);

#endif