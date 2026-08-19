#include <stdio.h>
#include <stdlib.h> // for qsort()

int cmp(const void* a, const void* b) {
	fprintf(stderr, ">>> Entering cmp(a=%p,b=%p)\n", a, b);
    const int *A = a, *B = b;
	fprintf(stderr, "<<< Exiting cmp(a=%p,b=%p)\n", a, b);
    return (*A > *B) - (*A < *B);
}

int threeSumClosest(int* nums, int nums_size, int target) {
	fprintf(stderr, ">>> Entering threeSumClosest(nums=%p,nums_size=%p,target=%d)\n", nums, nums_size, target);
    int i, j, k, result, sum3;
    qsort(nums, nums_size, sizeof(int), cmp);
    result = nums[0] + nums[1] + nums[2];
	fprintf(stderr, "threeSumClosest(nums=%p,nums_size=%d,target=%d): result → %d\n", nums, nums_size, target, result);
    for (i = 0; i < nums_size - 2; i++) {
        j = i + 1;
        k = nums_size - 1;
        while (j < k) {
            sum3 = nums[i] + nums[j] + nums[k];
			fprintf(stderr, "threeSumClosest(nums=%p,nums_size=%d,target=%d): sum3 → %d\n", nums, nums_size, target, sum3);
            if (abs(target - sum3) < abs(target - result)) {
                result = sum3;
            }
            if (sum3 < target) {
                j++;
            } else if (sum3 > target) {
                k--;
            } else {
                return sum3;
            }
        }
    }
	fprintf(stderr, "<<< Exiting threeSumClosest(nums=%p,nums_size=%p,target=%d)\n", nums, nums_size, target);
    return result;
}
