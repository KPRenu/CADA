#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

long long factorial(long n) {
    long long i, out = 1;
    for (i = 1; i <= n; i++)
        out *= i;
    return out;
}

int main(int argc, char **argv) {
    int i, threads;
    long long *x;
    long long n = 12;

    if (argc > 1) {
        threads = atoi(argv[1]);
        if (omp_get_dynamic()) {
            omp_set_dynamic(0);
            printf("called omp_set_dynamic(0)\n");
        }
        omp_set_num_threads(threads);
    }

    printf("%d threads\n", omp_get_max_threads());

    x = (long long *)malloc(n * sizeof(long long));

    // Parallel precompute factorials (optional)
    #pragma omp parallel for
    for (i = 0; i < n; i++)
        x[i] = factorial(i);

    int j = 0;
    for (i = 1; i < n; i++) {
        j += i;
        x[i] = j * x[i - 1]; // sequential dependency
    }

    for (i = 0; i < n; i++)
        printf("factorial(%2d)=%14lld x[%2d]=%14lld\n", i, factorial(i), i, x[i]);

    free(x);
    return 0;
}
