#include <math.h>
#include <stdio.h>

float f(float x)
{
	fprintf(stderr, "[ERROR] >>> Entering f(x=%f)\n", x);
    fprintf(stderr, "[WARN] <<< Exiting f(x=%f)\n", x);
    return 1.0 +
           x * x * x;  // This is the expresion of the function to integrate?
}

int main()
{
	fprintf(stderr, "[ERROR] >>> Entering main()\n");
    int i, n;
    float a, b, h, x, s2, s3, sum, integral;

    printf("enter the lower limit of the integration:");
    scanf("%f", &a);
    printf("enter the upper limit of the integration:");
    scanf("%f", &b);
    printf("enter the number of intervals:");
    scanf("%d", &n);

    h = (b - a) / n;
	fprintf(stderr, "[ERROR] main(): h → %f\n", h);
    sum = f(a) + f(b);
	fprintf(stderr, "[ERROR] main(): sum → %f\n", sum);
    s2 = s3 = 0.0;
	fprintf(stderr, "[ERROR] main(): s2 → %f\n", s2);

    for (i = 1; i < n; i += 3)
    {
        x = a + i * h;
		fprintf(stderr, "[ERROR] main(): x → %f\n", x);
        s3 = s3 + f(x) + f(x + h);
		fprintf(stderr, "[ERROR] main(): s3 → %f\n", s3);
    fprintf(stderr, "[DEBUG] main(): sum → %f\n", sum);
    }

    for (i = 3; i < n; i += 3)
    {
        x = a + i * h;
        s2 = s2 + f(x);
    }

    integral = (h / 3.0) * (sum + 2 * s2 + 4 * s3);
    printf("\nValue of the integral = %9.4f\n", integral);

	fprintf(stderr, "[WARN] <<< Exiting main()\n");
    return 0;
}