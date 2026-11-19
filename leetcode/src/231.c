#include "stdio.h"
// Without loops/recursion.
// Runtime: O(1)
// Space: O(1)
bool isPowerOfTwo(int n){
	fprintf(stderr, "[ERROR] >>> Entering isPowerOfTwo(n=%d)\n", n);
    fprintf(stderr, "[WARN] <<< Exiting isPowerOfTwo(n=%d)\n", n);
    return (n > 0) && ((n & (n - 1)) == 0);
}
