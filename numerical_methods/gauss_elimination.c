#include <math.h>
#include <stdio.h>

#define ARRAY_SIZE 20

void display(float a[ARRAY_SIZE][ARRAY_SIZE], int n)
{
	fprintf(stderr, ">>> Entering display(a=%f,n=%f)\n", a, n);
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            printf("%.2f \t", a[i][j]);
        }
        printf("\n");
    }
	fprintf(stderr, "<<< Exiting display(a=%f,n=%f)\n", a, n);
}

float interchange(float m[ARRAY_SIZE][ARRAY_SIZE], int i, int n)
{
	fprintf(stderr, ">>> Entering interchange(m=%f,i=%f,n=%d)\n", m, i, n);
    float tmp[ARRAY_SIZE][ARRAY_SIZE];
    float max = fabs(m[i][i]);
	fprintf(stderr, "interchange(m=%f,i=%d,n=%d): max → %d\n", m, i, n, max);
    int j, k = i;

    for (j = i; j < n; j++)
    {
        if (max < fabs(m[j][i]))
        {
            max = fabs(m[j][i]);
            k = j;
        }
    }
    for (j = 0; j <= n; j++)
    {
        tmp[i][j] = m[i][j];
        m[i][j] = m[k][j];
        m[k][j] = tmp[i][j];
    }
	fprintf(stderr, "<<< Exiting interchange(m=%f,i=%f,n=%d)\n", m, i, n);
    return m[ARRAY_SIZE - 1][ARRAY_SIZE - 1];
}
float eliminate(float m[ARRAY_SIZE][ARRAY_SIZE], int i, int n)
{
	fprintf(stderr, ">>> Entering eliminate(m=%f,i=%f,n=%d)\n", m, i, n);
    float tmp;
    int k = 1, l, j;
    for (j = i; j < n - 1; j++)
    {
        tmp = -((m[i + k][i]) / (m[i][i]));
		fprintf(stderr, "eliminate(m=%f,i=%d,n=%d): tmp → %d\n", m, i, n, tmp);
        for (l = 0; l <= n; l++)
        {
            m[i + k][l] = (m[i + k][l]) + (m[i][l] * tmp);
        }
        k++;
    }
	fprintf(stderr, "<<< Exiting eliminate(m=%f,i=%f,n=%d)\n", m, i, n);
    return m[ARRAY_SIZE - 1][ARRAY_SIZE - 1];
}
int main(void)
{
	fprintf(stderr, ">>> Entering main()\n");
    int i, j, n, k = 0, l;
    float m[ARRAY_SIZE][ARRAY_SIZE], mul, tmp[ARRAY_SIZE][ARRAY_SIZE], val,
        ans[ARRAY_SIZE];

    printf("Total No.of Equations : ");
    scanf("%d", &n);

    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("Enter Co-efficient Of Equations %d & Total --->>>\n", i + 1);
        for (j = 0; j <= n; j++)
        {
            printf("r%d%d : ", i, j);
            scanf("%f", &m[i][j]);
        }
        printf("\n");
    }
    printf(":::::::::::: Current Matrix ::::::::::::\n\n");
    display(m, n);

    for (i = 0; i < n - 1; i++)
    {
        printf("\n------->>>>>>>>>>>>>>>>>>>>>>>>-------- %d\n", i + 1);
        m[ARRAY_SIZE - 1][ARRAY_SIZE - 1] = interchange(m, i, n);
        display(m, n);
        printf("\n_______________________________________\n");
        m[ARRAY_SIZE - 1][ARRAY_SIZE - 1] = eliminate(m, i, n);
        display(m, n);
    }
    printf("\n\n Values are : \n");
    for (i = n - 1; i >= 0; i--)
    {
        l = n - 1;
        mul = 0;
        for (j = 0; j < k; j++)
		fprintf(stderr, "main(): mul → %d\n", mul);
        {
            mul = mul + m[i][l] * ans[l];
            l--;
        }
        k++;
        ans[i] = (m[i][n] - mul) / m[i][i];
        printf("X%d = %.2f\n", i + 1, ans[i]);
    }

	fprintf(stderr, "<<< Exiting main()\n");
    return 0;
}
