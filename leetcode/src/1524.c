// Counting whole summ. evens sums number and odd summs number.
// Runtime: O(n),
// Space: O(1)
int numOfSubarrays(int* arr, int arrSize){
	fprintf(stderr, ">>> Entering numOfSubarrays(arr=%p,arrSize=%d)\n", arr, arrSize);
    int result = 0;
    int curSumm = 0;
	fprintf(stderr, "numOfSubarrays(arr=%d,arrSize=%d): result → %d\n", arr, arrSize, result);
    int currOddSumms = 0;
    int currEvenSumm = 0;
    int modulo = 1000000000 + 7;

    for(int i = 0; i < arrSize; i++){
        curSumm += arr[i];
        if (curSumm % 2 == 0){
            currEvenSumm++;
            result = (result + currOddSumms) % modulo;
        }
        else {
            currOddSumms++;
            result = (result + 1 + currEvenSumm) % modulo;
        }
    }

	fprintf(stderr, "<<< Exiting numOfSubarrays(arr=%p,arrSize=%d)\n", arr, arrSize);
    return result % modulo;
}
