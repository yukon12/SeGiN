#include <stddef.h>
#include <SeGiN/mathematics.h>
#include <SeGiN/kadane.h>

int SGN_kadaneMinimum(int* array, int size, int* leftBound, int* rightBound)
{
    int currentValue = 0;
    int minimalValue = 0;
    int currentLeftBound = 0;
    int minimalLeftBound = 0;
    int currentRightBound = 0;
    int minimalRightBound = 0;

    for(;currentRightBound<size; currentRightBound++)
    {
        if(currentValue>0)
        {
            currentLeftBound = currentRightBound;
            currentValue = 0;
        }

        currentValue += array[currentRightBound];

        if(currentValue<minimalValue)
        {
            minimalValue = currentValue;
            minimalLeftBound = currentLeftBound;
            minimalRightBound = currentRightBound;
        }
    }

    if(leftBound!=NULL) *leftBound = minimalLeftBound;
    if(rightBound!=NULL) *rightBound = minimalRightBound;
    return minimalValue;
}

int SGN_kadaneMaximum(int* array, int size, int* leftBound, int* rightBound)
{
    int currentValue = 0;
    int maximalValue = 0;
    int currentLeftBound = 0;
    int maximalLeftBound = 0;
    int currentRightBound = 0;
    int maximalRightBound = 0;

    for(;currentRightBound<size; currentRightBound++)
    {
        if(currentValue<0)
        {
            currentLeftBound = currentRightBound;
            currentValue = 0;
        }

        currentValue += array[currentRightBound];

        if(currentValue>maximalValue)
        {
            maximalValue = currentValue;
            maximalLeftBound = currentLeftBound;
            maximalRightBound = currentRightBound;
        }
    }

    if(leftBound!=NULL) *leftBound = maximalLeftBound;
    if(rightBound!=NULL) *rightBound = maximalRightBound;
    return maximalValue;
}
