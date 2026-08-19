#include <stdio.h>

int main()
{
	fprintf(stderr, ">>> Entering main()\n");
    int n, sum = 0, i, num;
    printf("Enter number: ");
    scanf("%d", &n);
    num = n;
	fprintf(stderr, "main(): num → %d\n", num);
    while (n != 0)
    {
        i = n % 10;
        sum = sum + (i * i * i);
        n = n / 10;
		fprintf(stderr, "main(): sum → %d\n", sum);
    }
    if (sum == num)
    {
        printf("%d is an armstrong number!\n", num);
    }
    else
    {
        printf("%d is not an armstrong number!\n", num);
    }
	fprintf(stderr, "<<< Exiting main()\n");
    return 0;
}
