#include <stdlib.h>
#include <assert.h>
#include <SeGiN/mathematics.h>
#include <SeGiN/prefix_sum_array.h>

int* SGN_constructPrefixSumArray(int* array, int size)
{
    int* prefixSumArray = (int*)malloc(size*sizeof(int));
    prefixSumArray[0] = array[0];
    for(int i = 1; i < size; i++) prefixSumArray[i] = prefixSumArray[i-1]+array[i];
    return prefixSumArray;
}

int SGN_queryPSA(int* prefixSumArray, int size, int left, int right)
{
    assert(left>=0&&left<size&&right>=0&&right<size);
    int sum = prefixSumArray[right];
    if(left>0) sum -= prefixSumArray[left-1];
    return sum;
}
