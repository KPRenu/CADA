#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define AA 10
#define BB 5
#define CC 7
int main(int argc, char *argv[])
{
    int tid, nthreads, i, j, k, chunk;
    int a[AA][BB], b[BB][CC], c[AA][CC];
    chunk = 10;

#pragma omp parallel shared(a, b, c, nthreads, chunk) private(tid, i, j, k)
    {
        tid = omp_get_thread_num();
        if (tid == 0)
        {
            nthreads = omp_get_num_threads();
            printf("Starting matrix multiple with %d threads\n", nthreads);
            printf("Initializing matrices...\n");
        }

#pragma omp for schedule(static, chunk)
        for (i = 0; i < AA; i++)
            for (j = 0; j < BB; j++)
                a[i][j] = i + j;
#pragma omp for schedule(static, chunk)
        for (i = 0; i < BB; i++)
            for (j = 0; j < CC; j++)
                b[i][j] = i * j;
#pragma omp for schedule(static, chunk)
        for (i = 0; i < AA; i++)
            for (j = 0; j < CC; j++)
                c[i][j] = 0;

        printf("Thread %d starting matrix multiply...\n", tid);
#pragma omp for schedule(static, chunk)
        for (i = 0; i < AA; i++)
        {
            printf("Thread=%d did row=%d\n", tid, i);
            for (j = 0; j < CC; j++)
            {
                for (k = 0; k < BB; k++)
                {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
    }

    printf("******************************************************\n");
    printf("Result Matrix:\n");
    for (i = 0; i < AA; i++)
    {
        for (j = 0; j < CC; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    printf("******************************************************\n");
    printf("Done.\n");
}