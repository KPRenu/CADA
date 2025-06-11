#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 100000000

int main(int argc, char **argv)
{
    int *a;
    int i, k, threads, pcount;
    double t1, t2;

    if (argc > 1)
    {
        threads = atoi(argv[1]);
        if (omp_get_dynamic())
        {
            omp_set_dynamic(0);
            printf("called omp_set_dynamic(0)\n");
        }
        omp_set_num_threads(threads);
    }

    printf("%d threads max\n", omp_get_max_threads());

    a = (int *)malloc((N + 1) * sizeof(int));
    if (!a)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Initialize array
    for (i = 2; i <= N; i++)
        a[i] = 1;

    t1 = omp_get_wtime();

    for (k = 2; k * k <= N; k++)
    {
        if (a[k])
        {
            #pragma omp parallel for schedule(dynamic)
            for (i = k * k; i <= N; i += k)
                a[i] = 0;
        }
    }

    t2 = omp_get_wtime();
    printf("%.2f seconds\n", t2 - t1);

    // Count primes
    pcount = 0;
    for (i = 2; i <= N; i++)
    {
        if (a[i])
            pcount++;
    }

    printf("%d primes between 0 and %d\n", pcount, N);
    free(a);
    return 0;
}
