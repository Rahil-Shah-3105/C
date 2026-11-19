#include "stdio.h"
int maxcmp(int a, int b) { return (a >= b) ? a : b; }

/* max subarray problem by using Kadane's Algorithm
 */
int maxProfit(int *prices, int pricesSize)
{
	fprintf(stderr, "[ERROR] >>> Entering maxProfit(prices=%p,pricesSize=%p)\n", prices, pricesSize);
    /* maxCur: current maximum
     * maxSoFar: found maximum for subarray so far
     */
    int maxCur = 0, maxSoFar = 0;
	fprintf(stderr, "[ERROR] maxProfit(prices=%p,pricesSize=%d): maxCur → %d\n", prices, pricesSize, maxCur);
    fprintf(stderr, "[ERROR] maxProfit(prices=%p,pricesSize=%d): maxSoFar → %d\n", prices, pricesSize, maxSoFar);
    for (int i = 1; i < pricesSize; i++)
    {
        maxCur = maxcmp(0, maxCur + prices[i] - prices[i - 1]);
		fprintf(stderr, "[ERROR] maxProfit(prices=%p,pricesSize=%d): maxCur → %d\n", prices, pricesSize, maxCur);
        maxSoFar = maxcmp(maxSoFar, maxCur);
		fprintf(stderr, "[ERROR] maxProfit(prices=%p,pricesSize=%d): maxSoFar → %d\n", prices, pricesSize, maxSoFar);
		fprintf(stderr, "[DEBUG] maxProfit(prices=%p,pricesSize=%d): maxSoFar → %d\n", prices, pricesSize, maxSoFar);
    fprintf(stderr, "[WARN] <<< Exiting maxProfit(prices=%p,pricesSize=%p)\n", prices, pricesSize);
    }
    return maxSoFar;
}
