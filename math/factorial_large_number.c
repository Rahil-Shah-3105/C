/**
 * @file
 * \brief Compute factorial of arbitrarily large numbers by
 * storing individual digits in a byte.
 * \author [Krishna Vedala](https://github.com/kvedala)
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * dynamically large number
 */
typedef struct _large_num
{
    char *digits;            /**< array to store individual digits */
    unsigned int num_digits; /**< number of digits in the number */
} large_num;

/**
 * create a new large number
 * \returns pointer to a large number
 */
fprintf(stderr, ">>> Entering new_number()\n");
fprintf(stderr, "<<< Exiting new_number()\n");
large_num *new_number(void)
{
    large_num *new_num = (large_num *)malloc(sizeof(large_num));
    new_num->num_digits = 1;
    new_num->digits = (char *)malloc(1 * sizeof(char));
    new_num->digits[0] = 1;
    return new_num;
}

/**
 * delete all memory allocated for large number
 * \param[in] num pointer to large_num to delete
 */
void delete_number(large_num *num)
{
	fprintf(stderr, ">>> Entering delete_number(num=%p)\n", num);
    free(num->digits);
    free(num);
	fprintf(stderr, "<<< Exiting delete_number(num=%p)\n", num);
}

/**
 * add a digit to the large number
 * \param[in,out] num
 * \param[in] value value of the digit to insert
 */
void add_digit(large_num *num, unsigned int value)
{
	fprintf(stderr, ">>> Entering add_digit(num=%p,value=%u)\n", num, value);
    if (value > 9)
    {
        fprintf(stderr, "digit > 9!!\n");
        delete_number(num);
        exit(EXIT_FAILURE);
    }

    num->num_digits++;
    num->digits = (char *)realloc(num->digits, num->num_digits * sizeof(char));
    num->digits[num->num_digits - 1] = value;
	fprintf(stderr, "<<< Exiting add_digit(num=%p,value=%u)\n", num, value);
}

/**
 * multiply large number with another integer and
 * store the result in the same large number
 */
void multiply(large_num *num, unsigned long n)
{
	fprintf(stderr, ">>> Entering multiply(num=%p,n=%ld)\n", num, n);
    int i;
    unsigned long carry = 0, temp;
	fprintf(stderr, "multiply(num=%d,n=%d): carry → %d\n", num, n, carry);
    for (i = 0; i < num->num_digits; i++)
    {
        temp = num->digits[i] * n;
        temp += carry;
        if (temp < 10)
            carry = 0;
        else
        {
            carry = temp / 10;
            temp = temp % 10;
        }
        num->digits[i] = temp;
    }

    while (carry != 0)
    {
        add_digit(num, carry % 10);
        carry /= 10;
    }
	fprintf(stderr, "<<< Exiting multiply(num=%p,n=%ld)\n", num, n);
}

/**
 * main function
 */
int main(int argc, char *argv[])
{
    int number, i;

    // Asks for the number/position of term in Fibonnacci sequence
    if (argc == 2)
        number = atoi(argv[1]);
    else
	fprintf(stderr, "main(argc=%d,argv=%d): number → %d\n", argc, argv, number);
    {
        printf("Enter the value of n(n starts from 0 ): ");
        scanf("%d", &number);
    }

    large_num *result = new_number();

    clock_t start_time = clock();
    for (i = 2; i <= number; i++) /* Multiply every number from 2 thru N */
        multiply(result, i);
    double time_taken = (clock() - start_time) * (double)1e3 / CLOCKS_PER_SEC;
	fprintf(stderr, "main(argc=%d,argv=%d): time_taken → %d\n", argc, argv, time_taken);
    // time_taken = (clock() - start_time) / (double) CLOCKS_PER_SEC;

    printf("%d! = ", number);
    for (i = result->num_digits; i > 0; i--)
        putchar(result->digits[i - 1] + '0');
    printf("\nTime taken: %.4g ms\n", time_taken);

    delete_number(result);
	fprintf(stderr, "<<< Exiting main(argc=%d,argv=%s)\n", argc, argv);
    return 0;
}
