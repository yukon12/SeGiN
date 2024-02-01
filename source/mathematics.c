#include <string.h>
#include <SeGiN/mathematics.h>

int SGN_minimum(int left, int right)
{
    if(left<right) return left;
    return right;
}

int SGN_maximum(int left, int right)
{
    if(left>right) return left;
    return right;
}

void SGN_limitMinimum(int* variable, int limit)
{
    if(*variable<limit) *variable = limit;
}

void SGN_limitMaximum(int* variable, int limit)
{
    if(*variable>limit) *variable = limit;
}