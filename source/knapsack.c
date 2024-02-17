#include <stdlib.h>
#include <SeGiN/mathematics.h>
#include <SeGiN/knapsack.h>

int knapsack(int* weight, int* profit, int amount, int maximalWeight)
{
    int* dp = (int*)calloc(maximalWeight+1, sizeof(int));
    for(int i = 0; i < amount; i++)
    {
        for(int j = maximalWeight; j >= 0 && j >= weight[i]; j--)
        {
            dp[j] = SGN_maximum(dp[j], dp[j-weight[i]]+profit[i]);
        }
    }
    return dp[maximalWeight];
}
