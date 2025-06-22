#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
long long n = 12;

long long fact(long long n)
{
    long long out = 1;
    for (int i = 1; i <= n; i++)
    {
        out *= i;
    }
    return out;
}
int main(int argc, char **argv)
{
    int tid, threads, i, j;
    long long *x;
    if (argc > 1)
    {
        threads = atoi(argv[1]);
        if (omp_get_dynamic())
        {
            omp_set_dynamic(0);
            printf("set dynamic is called\n");
        }
        omp_set_num_threads(threads);
    }
    printf("%d threads\n", omp_get_max_threads());

    x = (long long *)malloc((n) * sizeof(long long));

    for (i = 0; i < n; i++)
    {
        x[i] = fact(i);
    }

    j = 0;

#pragma omp parallel for firstprivate(x, j)
    for (i = 1; i < n; i++)
    {
        j += i;
        x[i] = j * x[i - 1];
    }

    for (i = 0; i < n; i++)
    {
        printf("factorial of %d=%14lld\t x[%d]=%14lld\n", i, fact(i), i, x[i]);
    }
}