#include <SeGiN/mathematics.h>
#include <SeGiN/kadane.h>

int SGN_maximumSubarraySum(int* array, int size)
{
    int maximalSuffixSum = 0;
    int result = 0;
    for(int i = 0; i < size; i++)
    {
        maximalSuffixSum += array[i];
        SGN_limitMinimum(&maximalSuffixSum, 0);
        SGN_limitMinimum(&result, maximalSuffixSum);
    }
    return result;
}

int SGN_minimumSubarraySum(int* array, int size)
{
    int minimalSuffixSum = 0;
    int result = 0;
    for(int i = 0; i < size; i++)
    {
        minimalSuffixSum += array[i];
        SGN_limitMaximum(&minimalSuffixSum, 0);
        SGN_limitMaximum(&result, minimalSuffixSum);
    }
    return result;
}
