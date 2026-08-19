#include <math.h>
#include <stdio.h>

float f(float x)
{
	fprintf(stderr, ">>> Entering f(x=%f)\n", x);
    fprintf(stderr, "<<< Exiting f(x=%f)\n", x);
    return 1.0 +
           x * x * x;  // This is the expresion of the function to integrate?
}

int main()
{
	fprintf(stderr, ">>> Entering main()\n");
    int i, n;
    float a, b, h, x, s2, s3, sum, integral;

    printf("enter the lower limit of the integration:");
    scanf("%f", &a);
    printf("enter the upper limit of the integration:");
    scanf("%f", &b);
    printf("enter the number of intervals:");
    scanf("%d", &n);

    h = (b - a) / n;
	fprintf(stderr, "main(): h → %d\n", h);
    sum = f(a) + f(b);
    s2 = s3 = 0.0;
	fprintf(stderr, "main(): s2 → %d\n", s2);
	fprintf(stderr, "main(): s3 → %d\n", s3);
	fprintf(stderr, "main(): sum → %d\n", sum);

    for (i = 1; i < n; i += 3)
    {
        x = a + i * h;
		fprintf(stderr, "main(): x → %d\n", x);
        s3 = s3 + f(x) + f(x + h);
    }

    for (i = 3; i < n; i += 3)
    {
        x = a + i * h;
        s2 = s2 + f(x);
    }

    integral = (h / 3.0) * (sum + 2 * s2 + 4 * s3);
	fprintf(stderr, "main(): integral → %d\n", integral);
    printf("\nValue of the integral = %9.4f\n", integral);

	fprintf(stderr, "<<< Exiting main()\n");
    return 0;
}