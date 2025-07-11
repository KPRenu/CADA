#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define N 10
int main(int argc, char *argv[])
{
    int i, nthreads, tid;
    int a[N], b[N], c[N], d[N];
 
    for (i = 0; i < N; i++)
    {
        a[i] = i + 1;
        b[i] = i * 2;
        c[i] = d[i] = 0;
    }
#pragma omp parallel shared(a, b, c, d, nthreads) private(i, tid)
    {
        tid = omp_get_thread_num();
        if (tid == 0)
        {
            nthreads = omp_get_num_threads();
            printf("Number of threads = %d\n", nthreads);
        }
        printf("Thread %d starting...\n", tid);
#pragma omp sections nowait
        {
#pragma omp section
            {
                printf("Thread %d doing section 1\n", tid);
                for (i = 0; i < N; i++)
                {
                    c[i] = a[i] + b[i];
                    printf("Thread %d: c[%d]= %d\n", tid, i, c[i]);
                }
            }
#pragma omp section
            {
                printf("Thread %d doing section 2\n", tid);
                for (i = 0; i < N; i++)
                {
                    d[i] = a[i] * b[i];
                    printf("Thread %d: d[%d]= %d\n", tid, i, d[i]);
                }
            }
        } 
        printf("Thread %d done.\n", tid);
    } 
     for (i = 0; i < N; i++)
    {
       printf("c[%d]=%d  and d[%d]=%d \n",i,c[i],i,d[i]);
    }
}
