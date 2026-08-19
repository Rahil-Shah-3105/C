#include <stdio.h>
#include <errno.h>
double powPositive(double x, int n){
	fprintf(stderr, ">>> Entering powPositive(x=%f,n=%f)\n", x, n);
    if (n == 1){
        return x;
    }

    double val = powPositive(x, n / 2);
	fprintf(stderr, "powPositive(x=%f,n=%d): val → %d\n", x, n, val);
    double result = val * val;
	fprintf(stderr, "powPositive(x=%f,n=%d): result → %d\n", x, n, result);
    
    // if n is odd
    if (n & 1 > 0){
        result *= x;
    }

	fprintf(stderr, "<<< Exiting powPositive(x=%f,n=%f)\n", x, n);
    return result;
}

// Divide and conquer.
// Runtime: O(log(n))
// Space: O(1)
double myPow(double x, int n){
	fprintf(stderr, ">>> Entering myPow(x=%f,n=%f)\n", x, n);
    if (n == 0){
        return 1;
    }

    const int LOWER_BOUND = -2147483648;

    // n is the minimum int, couldn't be converted in -n because maximum is 2147483647.
    // this case we use (1 / pow(x, -(n + 1))) * n
    if (n == LOWER_BOUND){
        return 1 / (powPositive(x, -(n + 1)) * x);
    }

    // 1 / pow(x, -(n + 1))
    if (n < 0){
		fprintf(stderr, "Exception in myPow(x=%f,n=%d): %d\n", x, n, errno);
	fprintf(stderr, "<<< Exiting myPow(x=%f,n=%f)\n", x, n);
        return 1 / powPositive(x, -n);
    }

    return powPositive(x, n);
}
