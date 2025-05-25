#include <stdio.h>
#include <omp.h>
#define N 20
int main()
{
    int fib[N];

    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i < N; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    printf("Fibonacci sequence (sequential):\n");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", fib[i]);
    }
    printf("\n");

 #pragma omp parallel for unroll
    {
        for (int i = 2; i < N; i += 2) {
            fib[i] = fib[i - 1] + fib[i - 2];
            if (i + 1 < N) {
                fib[i + 1] = fib[i] + fib[i - 1];
            }
        }
    }
    printf("Fibonacci sequence (parallel with loop unrolling):\n");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", fib[i]);
    }
    printf("\n");
    return 0;
}
