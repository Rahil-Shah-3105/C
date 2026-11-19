#include "stdio.h"
// Counting whole summ. evens sums number and odd summs number.
// Runtime: O(n),
// Space: O(1)
int numOfSubarrays(int* arr, int arrSize){
	fprintf(stderr, "[ERROR] >>> Entering numOfSubarrays(arr=%p,arrSize=%p)\n", arr, arrSize);
    int result = 0;
    int curSumm = 0;
    int currOddSumms = 0;
    int currEvenSumm = 0;
    int modulo = 1000000000 + 7;

    for(int i = 0; i < arrSize; i++){
        curSumm += arr[i];
        if (curSumm % 2 == 0){
            currEvenSumm++;
            result = (result + currOddSumms) % modulo;
			fprintf(stderr, "[ERROR] numOfSubarrays(arr=%p,arrSize=%d): result → %d\n", arr, arrSize, result);
        }
        else {
            currOddSumms++;
            result = (result + 1 + currEvenSumm) % modulo;
        }
    }

	fprintf(stderr, "[WARN] <<< Exiting numOfSubarrays(arr=%p,arrSize=%p)\n", arr, arrSize);
    return result % modulo;
}
