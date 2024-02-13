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

int SGN_exponentiation(int base, int exponent, int modulus)
{
    if(exponent==0) return 1;
    int result = SGN_exponentiation(base, exponent/2, modulus);
    result *= result;
    result %= modulus;
    if(exponent%2==1)
    {
        result *= base;
        result %= modulus;
    }
    return result;
}
