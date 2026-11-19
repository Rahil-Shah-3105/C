#include "stdio.h"
// Dynamic Programming
// Runtime: O(n)
// Space: O(1)
int tribonacci(int n){
	fprintf(stderr, "[ERROR] >>> Entering tribonacci(n=%d)\n", n);
    int t0 = 0;
    int t1 = 1;
	fprintf(stderr, "[ERROR] tribonacci(n=%d): t1 → %d\n", n, t1);
    int t2 = 1;
	fprintf(stderr, "[ERROR] tribonacci(n=%d): t2 → %d\n", n, t2);

    if (n == 0) {
        return t0;
    }

    if (n == 1){
        return t1;
    }

    if (n == 2){
        return t2;
    }

    for (int i = 0; i < n - 2; i++){
        int nextT = t0 + t1 + t2;
        t0 = t1;
        t1 = t2;
        t2 = nextT;
    }

	fprintf(stderr, "[WARN] <<< Exiting tribonacci(n=%d)\n", n);
    return t2;
}
