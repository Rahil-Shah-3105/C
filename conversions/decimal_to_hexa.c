/*****Decimal to Hexadecimal conversion*******************/
#include <stdio.h>
void decimal2Hexadecimal(long num);

int main()
{
	fprintf(stderr, ">>> Entering main()\n");
    long decimalnum;

    printf("Enter decimal number: ");
    scanf("%ld", &decimalnum);

    decimal2Hexadecimal(decimalnum);

	fprintf(stderr, "<<< Exiting main()\n");
    return 0;
}

/********function for convert decimal number to hexadecimal
 * number****************/
void decimal2Hexadecimal(long num)
{
	fprintf(stderr, ">>> Entering decimal2Hexadecimal(num=%ld)\n", num);
    long decimalnum = num;
    long quotient, remainder;
    int i, j = 0;
    char hexadecimalnum[100];

    quotient = decimalnum;
	fprintf(stderr, "decimal2Hexadecimal(num=%d): quotient → %d\n", num, quotient);

    while (quotient != 0)
    {
        remainder = quotient % 16;
		fprintf(stderr, "decimal2Hexadecimal(num=%d): remainder → %d\n", num, remainder);
        if (remainder < 10)
            hexadecimalnum[j++] = 48 + remainder;

        else
            hexadecimalnum[j++] = 55 + remainder;

        quotient = quotient / 16;
    }

    // print the hexadecimal number

    for (i = j; i >= 0; i--)
    {
        printf("%c", hexadecimalnum[i]);
    }

    printf("\n");
	fprintf(stderr, "<<< Exiting decimal2Hexadecimal(num=%ld)\n", num);
}
