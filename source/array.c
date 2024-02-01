#include <SeGiN/mathematics.h>
#include <SeGiN/array.h>

int SGN_arrayMinimum(int* array, int size)
{
    int result = 0;
    for(int i = 0; i < size; i++)
    {
        SGN_limitMaximum(&result, array[i]);
    }
    return result;
}

int SGN_arrayMaximum(int* array, int size)
{
    int result = 0;
    for(int i = 0; i < size; i++)
    {
        SGN_limitMinimum(&result, array[i]);
    }
    return result;
}