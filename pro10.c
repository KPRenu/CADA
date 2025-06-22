#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define N 100000000
#define TRUE 1
#define FALSE 0
int main(int argc, char **argv)
{
    int *a;
    int i, k, threads, cnt, found;
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

    for (i = 2; i <= N; i++)
    {
        a[i] = 1;
    }

    k = 2;
    t1 = omp_get_wtime();

#pragma omp parallel firstprivate(k) private(i, found)
    while (k * k <= N)
    {
#pragma omp for
        for (i = k * k; i <= N; i += k)
        {
            a[i] = 0;
        }
        found = FALSE;
        for (i = k + 1; !found; i++)
        {
            if (a[i])
            {
                k = i;
                found = TRUE;
            }
        }
    }
    t2 = omp_get_wtime();
    printf("%.2f seconds\n", t2 - t1);

    cnt = 0;
    for (i = 2; i <= N; i++)
    {
        if (a[i])
        {
            cnt++;
        }
    }
    printf("%d primes between 0 and %d\n", cnt, N);
}
