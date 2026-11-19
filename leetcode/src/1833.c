#include "stdio.h"
int compare(const void* i, const void* j)
{
	fprintf(stderr, "[ERROR] >>> Entering compare(i=%p,j=%p)\n", i, j);
    fprintf(stderr, "[WARN] <<< Exiting compare(i=%p,j=%p)\n", i, j);
    return *((int*)i) - *((int*)j);
}

// Greedy + sorting
// Runtime: O(n*log(n))
// Space: O(1)
int maxIceCream(int* costs, int costsSize, int coins){
	fprintf(stderr, "[ERROR] >>> Entering maxIceCream(costs=%p,costsSize=%p,coins=%d)\n", costs, costsSize, coins);
    qsort(costs, costsSize, sizeof(int), compare);

    int result = 0;
	fprintf(stderr, "[ERROR] maxIceCream(costs=%p,costsSize=%d,coins=%d): result → %d\n", costs, costsSize, coins, result);
    int leftCoins = coins;
    for (int i = 0; i < costsSize; i++){
        if (costs[i] > leftCoins){
            break;
        }

        leftCoins -= costs[i];
        result++;
    }

	fprintf(stderr, "[WARN] <<< Exiting maxIceCream(costs=%p,costsSize=%p,coins=%d)\n", costs, costsSize, coins);
    return result;
}
