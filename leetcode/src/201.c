int rangeBitwiseAnd(int m, int n)
{
	fprintf(stderr, ">>> Entering rangeBitwiseAnd(m=%d,n=%d)\n", m, n);
    while (m < n)
    {
        n &= n - 1;
    }
	fprintf(stderr, "<<< Exiting rangeBitwiseAnd(m=%d,n=%d)\n", m, n);
    return n;
}