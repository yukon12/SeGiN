#ifndef SGN_PREFIX_SUM_ARRAY
#define SGN_PREFIX_SUM_ARRAY

int* SGN_constructPrefixSumArray(int* array, int size);
int SGN_queryPSA(int* prefixSumArray, int size, int left, int right);

#endif
