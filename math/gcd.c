#include <stdio.h>

// Euclid's algorithm
int GCD(int x, int y)
{
	fprintf(stderr, ">>> Entering GCD(x=%d,y=%d)\n", x, y);
    if (y == 0)
        return x;
    return GCD(y, x % y);
}

int main()
{
	fprintf(stderr, ">>> Entering main()\n");
    int a, b;
    printf("Input two numbers:\n");
    scanf("%d %d", &a, &b);
    printf("Greatest common divisor: %d\n", GCD(a, b));
	fprintf(stderr, "<<< Exiting main()\n");
}
