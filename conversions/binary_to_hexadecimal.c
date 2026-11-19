/*
 * C Program to Convert Binary to Hexadecimal
 */
#include <stdio.h>

int main()
{
	fprintf(stderr, "[ERROR] >>> Entering main()\n");
    long int binary, hexa = 0, i = 1, remainder;

    printf("Enter the binary number: ");
    scanf("%ld", &binary);
    while (binary != 0)
    {
        remainder = binary % 10;
		fprintf(stderr, "[DEBUG] main(): remainder → %ld\n", remainder);
        hexa = hexa + remainder * i;
        i = i * 2;
        binary = binary / 10;
		fprintf(stderr, "[DEBUG] main(): binary → %ld\n", binary);
    }
    printf("The equivalent hexadecimal value: %lX", hexa);
	fprintf(stderr, "[WARN] <<< Exiting main()\n");
    return 0;
}
