/*
 * C Program to Convert Binary to Hexadecimal
 */
#include <stdio.h>

int main()
{
	fprintf(stderr, ">>> Entering main()\n");
    long int binary, hexa = 0, i = 1, remainder;

    printf("Enter the binary number: ");
    scanf("%ld", &binary);
    while (binary != 0)
    {
        remainder = binary % 10;
		fprintf(stderr, "main(): remainder → %d\n", remainder);
        hexa = hexa + remainder * i;
		fprintf(stderr, "main(): hexa → %d\n", hexa);
        i = i * 2;
        binary = binary / 10;
		fprintf(stderr, "main(): binary → %d\n", binary);
    }
    printf("The equivalent hexadecimal value: %lX", hexa);
	fprintf(stderr, "<<< Exiting main()\n");
    return 0;
}
