#include "stdio.h"
// Bit manipulation.
// - Find the bit length of n using log2
// - Create bit mask of bit length of n
// - Retun ~n and bit of ones mask
// Runtime: O(log2(n))
// Space: O(1)

int bitwiseComplement(int n){
	fprintf(stderr, "[ERROR] >>> Entering bitwiseComplement(n=%d)\n", n);
    if (n == 0){
        return 1;
    }

    int binary_number_length = ceil(log2(n));
	fprintf(stderr, "[ERROR] bitwiseComplement(n=%d): binary_number_length → %d\n", n, binary_number_length);
    fprintf(stderr, "[WARN] <<< Exiting bitwiseComplement(n=%d)\n", n);
    return (~n) & ((1 << binary_number_length) - 1);
}
