#include <stdlib.h>
#include <SeGiN/mathematics.h>
#include <SeGiN/prefix_sum.h>

SGN_PrefixSum* SGN_constructPrefixSum(int* array, int size)
{
    SGN_PrefixSum* prefixSum = (SGN_PrefixSum*)malloc(sizeof(SGN_PrefixSum));
    prefixSum->sum = (int*)malloc(size*sizeof(int));
    prefixSum->size = size;

    int* sum = prefixSum->sum;

    sum[0] = array[0];
    for(int i = 1; i < size; i++)
    {
        sum[i] = sum[i-1]+array[i];
    }

    return prefixSum;
}

int SGN_rangeSum(SGN_PrefixSum* prefixSum, int left, int right)
{
    int* sum = prefixSum->sum;
    int size = prefixSum->size;

    SGN_limitMinimum(&left, 0);
    SGN_limitMaximum(&left, size-1);
    SGN_limitMinimum(&right, 0);
    SGN_limitMaximum(&right, size-1);

    if(left==0) return sum[right];
    return sum[right]-sum[left-1];
}