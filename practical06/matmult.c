#include <stdio.h>

int main(void)
{
    int n = 5, p = 3, q = 4;
    double A[n][p], B[p][q], C[n][q];
    int i, j, k; // indices for loop

    // Initializing matrices
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < p; j++)
        {
            A[i][j] = i + j;
        }
    }
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < q; j++)
        {
            B[i][j] = i - j;
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < q; j++)
        {
            C[i][j] = 0.0;
        }
    }

    // Matrix multiplication code
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < q; j++)
        {
            for (k = 0; k < p; k++)
            {
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }

    // Printing the matrices
    printf("\nMatrix A:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < p; j++)
        {
            printf("%3.0f ", A[i][j]);
        }
        printf("\n");
    }
    printf("\nMatrix B:\n");
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < q; j++)
        {
            printf("%3.0f ", B[i][j]);
        }
        printf("\n");
    }
    printf("\nMatrix C = A*B:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < q; j++)
        {
            printf("%3.0f ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
