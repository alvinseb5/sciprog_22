#include <stdio.h>
#include <math.h>

double arctanh1(const double x, const double delta);
double arctanh2(const double x);

int main()
{

    double delta, x;
    // precision input
    printf("Enter the precision for Maclaurin series\n");
    scanf("%lf", &delta);

    int length = 1000;
    double tan1[length];
    double tan2[length];

    int j = 0;
    x = -0.9;

    // compare approximations
    while (x <= 0.9 && j < length)
    {
        tan1[j] = arctanh1(x, delta);
        tan2[j] = arctanh2(x);
        printf("The differences at x =%lf between them is %0.10lf\n", x, fabs(tan1[j] - tan2[j]));
        j++;
        x = x + 0.01;
    }

    return 0;
}

// Maclaurin series aproximation function
double arctanh1(const double x, const double delta)
{
    double arcTan = 0;
    double elem, val;
    int n = 0;

    do
    {
        val = 2 * n + 1;
        elem = pow(x, val) / val;
        arcTan += elem;
        n++;
    } while (fabs(elem) >= delta);

    return arcTan;
}

// using log function
double arctanh2(const double x)
{
    return ((log(1 + x) - log(1 - x)) / 2);
}