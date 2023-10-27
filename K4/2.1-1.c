#include<stdio.h>
#include<time.h>

long long int f(int n)
{
    if(n==1 || n==2 || n==0)
        return 1;
    else
        return f(n-1) + f(n-2);
}

int main()
{
    clock_t start_t, finish_t;
    start_t = clock();
    //Out put terms from 1 to 50.
    for(int i = 1; i < 51; i++)
        printf("F(%d)=%lld\n", i, f(i));
    finish_t = clock();
    printf("Run Time: %fs\n", (double)(finish_t - start_t) / CLOCKS_PER_SEC);
    return 0;
}