#include <stdio.h>

int main()
{
	fprintf(stderr, "[ERROR] >>> Entering main()\n");
    int n, sum = 0, i, num;
    printf("Enter number: ");
	fprintf(stderr, "[ERROR] main(): sum → %d\n", sum);
    scanf("%d", &n);
    num = n;
    while (n != 0)
    {
        i = n % 10;
        sum = sum + (i * i * i);
        n = n / 10;
		fprintf(stderr, "[DEBUG] main(): sum → %d\n", sum);
    }
    if (sum == num)
    {
        printf("%d is an armstrong number!\n", num);
    }
    else
    {
        printf("%d is not an armstrong number!\n", num);
    }
	fprintf(stderr, "[WARN] <<< Exiting main()\n");
    return 0;
}
