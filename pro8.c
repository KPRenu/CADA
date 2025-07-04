#include <omp.h>
#include <stdio.h>
int a, b, i, tid;
int x;
#pragma omp threadprivate(a, x)
int main()
{
    omp_set_dynamic(0);
    printf("1st Parallel Region:\n");
#pragma omp parallel private(b, tid)
    {
        tid = omp_get_thread_num();
        a = tid;
        b = tid;
        x = 1 * tid + 1;
        printf("Thread %d: a,b,x= %d %d %d\n", tid, a, b, x);
    }
    printf("************************************\n");
    printf("Master thread doing serial work here\n");
    printf("************************************\n");
    printf("2nd Parallel Region:\n");
#pragma omp parallel private(tid)
    {
        tid = omp_get_thread_num();
        printf("Thread %d: a,b,x= %d %d %d\n", tid, a, b, x);
    }
}