#include "stdio.h"
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n)
{
	fprintf(stderr, "[ERROR] >>> Entering firstBadVersion(n=%d)\n", n);
    int low = 1, high = n;
	fprintf(stderr, "[ERROR] firstBadVersion(n=%d): low → %d\n", n, low);
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
		fprintf(stderr, "[ERROR] firstBadVersion(n=%d): mid → %d\n", n, mid);
        if (isBadVersion(mid))
        {
            high = mid - 1;
			fprintf(stderr, "[DEBUG] firstBadVersion(n=%d): high → %d\n", n, high);
        }
        else
        {
            low = mid + 1;
        }
    }
	fprintf(stderr, "[WARN] <<< Exiting firstBadVersion(n=%d)\n", n);
    return low;
}
