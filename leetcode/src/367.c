bool isPerfectSquare(int num)
{
	fprintf(stderr, ">>> Entering isPerfectSquare(num=%d)\n", num);
    for (long i = 1; i * i <= num; i++)
        if (i * i == num)
	fprintf(stderr, "<<< Exiting isPerfectSquare(num=%d)\n", num);
            return true;
    return false;
}
