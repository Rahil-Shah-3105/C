// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n)
{
	fprintf(stderr, ">>> Entering firstBadVersion(n=%d)\n", n);
    int low = 1, high = n;
    while (low <= high)
	fprintf(stderr, "firstBadVersion(n=%d): low → %d\n", n, low);
    {
        int mid = low + (high - low) / 2;
		fprintf(stderr, "firstBadVersion(n=%d): mid → %d\n", n, mid);
        if (isBadVersion(mid))
        {
            high = mid - 1;
			fprintf(stderr, "firstBadVersion(n=%d): high → %d\n", n, high);
        }
        else
        {
            low = mid + 1;
        }
    }
	fprintf(stderr, "<<< Exiting firstBadVersion(n=%d)\n", n);
    return low;
}
