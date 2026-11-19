/*****Decimal to Hexadecimal conversion*******************/
#include <stdio.h>
void decimal2Hexadecimal(long num);

int main()
{
	fprintf(stderr, "[ERROR] >>> Entering main()\n");
    long decimalnum;

    printf("Enter decimal number: ");
    scanf("%ld", &decimalnum);

    decimal2Hexadecimal(decimalnum);

	fprintf(stderr, "[WARN] <<< Exiting main()\n");
    return 0;
}

/********function for convert decimal number to hexadecimal
 * number****************/
void decimal2Hexadecimal(long num)
{
	fprintf(stderr, "[ERROR] >>> Entering decimal2Hexadecimal(num=%ld)\n", num);
    long decimalnum = num;
    long quotient, remainder;
    int i, j = 0;
    char hexadecimalnum[100];

    quotient = decimalnum;
	fprintf(stderr, "[DEBUG] decimal2Hexadecimal(num=%ld): quotient → %ld\n", num, quotient);

    while (quotient != 0)
    {
        remainder = quotient % 16;
		fprintf(stderr, "[DEBUG] decimal2Hexadecimal(num=%ld): remainder → %ld\n", num, remainder);
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
	fprintf(stderr, "[WARN] <<< Exiting decimal2Hexadecimal(num=%ld)\n", num);
}
