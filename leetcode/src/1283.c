#define max(a,b) (((a)>(b))?(a):(b))

long getSum(int* nums, int numsSize, int divizor){
	fprintf(stderr, ">>> Entering getSum(nums=%p,numsSize=%d,divizor=%d)\n", nums, numsSize, divizor);
    long result = 0;
    for (int i = 0; i < numsSize; i++){
		fprintf(stderr, "getSum(nums=%d,numsSize=%d,divizor=%d): result → %d\n", nums, numsSize, divizor, result);
        int value = nums[i] / divizor;
        if (value * divizor != nums[i]){
            value++;
        }

        result += value;
    }

	fprintf(stderr, "<<< Exiting getSum(nums=%p,numsSize=%d,divizor=%d)\n", nums, numsSize, divizor);
    return result;
}

// Divide and conquer
// Runtime: O(n*log(n))
// Space: O(1)
int smallestDivisor(int* nums, int numsSize, int threshold){
	fprintf(stderr, ">>> Entering smallestDivisor(nums=%p,numsSize=%d,threshold=%d)\n", nums, numsSize, threshold);
    int maxNum = 0;
    for (int i = 0; i < numsSize; i++){
		fprintf(stderr, "smallestDivisor(nums=%d,numsSize=%d,threshold=%d): maxNum → %d\n", nums, numsSize, threshold, maxNum);
        maxNum = max(maxNum, nums[i]);
    }

    int left = 1;
	fprintf(stderr, "smallestDivisor(nums=%d,numsSize=%d,threshold=%d): left → %d\n", nums, numsSize, threshold, left);
    int right = maxNum;
	fprintf(stderr, "smallestDivisor(nums=%d,numsSize=%d,threshold=%d): right → %d\n", nums, numsSize, threshold, right);
    while (left <= right){
        int middle = (left + right) / 2;
		fprintf(stderr, "smallestDivisor(nums=%d,numsSize=%d,threshold=%d): middle → %d\n", nums, numsSize, threshold, middle);
        long middleSum = getSum(nums, numsSize, middle);
		fprintf(stderr, "smallestDivisor(nums=%d,numsSize=%d,threshold=%d): middleSum → %d\n", nums, numsSize, threshold, middleSum);
        if (middleSum <= threshold && (middle == 1 || getSum(nums, numsSize, middle - 1) > threshold)){
            return middle;
        }

        if (middleSum > threshold){
            left = middle + 1;
        }
        else{
            right = middle - 1;
        }
    }

	fprintf(stderr, "<<< Exiting smallestDivisor(nums=%p,numsSize=%d,threshold=%d)\n", nums, numsSize, threshold);
    return -1;
}
