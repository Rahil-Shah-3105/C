// A number is called as Armstrong number if sum of cubes of digits of number is
// equal to the number itself.
// For Example 153 is an Armstrong number because 153 = 1³+5³+3³.
#include <stdio.h>

// Function to calculate x raised to the power y
int power(int x, unsigned int y)
{
	fprintf(stderr, ">>> Entering power(x=%d,y=%u)\n", x, y);
    if (y == 0)
        return 1;
    if (y % 2 == 0)
        return power(x, y / 2) * power(x, y / 2);
    return x * power(x, y / 2) * power(x, y / 2);
}

// Function to calculate order of the number
int order(int x)
{
	fprintf(stderr, ">>> Entering order(x=%d)\n", x);
    int n = 0;
    while (x)
    {
        n++;
        x = x / 10;
    }
	fprintf(stderr, "<<< Exiting order(x=%d)\n", x);
    return n;
}

// Function to check whether the given number is
// Armstrong number or not
int isArmstrong(int x)
{
	fprintf(stderr, ">>> Entering isArmstrong(x=%d)\n", x);
    // Calling order function
    int n = order(x);
	fprintf(stderr, "isArmstrong(x=%d): n → %d\n", x, n);
    int temp = x, sum = 0;
    while (temp)
    {
        int r = temp % 10;
        sum += power(r, n);
        temp = temp / 10;
    }

    // If satisfies Armstrong condition
    if (sum == x)
        return 1;
    else
        return 0;
}

//
int main()
{
	fprintf(stderr, ">>> Entering main()\n");
    int x = 153;
    if (isArmstrong(x) == 1)
        printf("True\n");
    else
        printf("False\n");

    x = 1253;
    if (isArmstrong(x) == 1)
        printf("True\n");
    else
        printf("False\n");

	fprintf(stderr, "<<< Exiting main()\n");
    return 0;
}
