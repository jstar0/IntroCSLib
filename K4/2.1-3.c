#include<stdio.h>
#include<time.h>

int main()
{
    clock_t start_t, finish_t;
    start_t = clock();
    long long int a = 1, b = 1, tmp;
    //Output terms from 1 to 50.
    printf("F(1)=1\n");
    for(int i = 1; i < 50; i++)
    {
        tmp = a;
        a = b;
        b = a + tmp;
        printf("F(%d)=%lld\n", i + 1, a);
    }
    finish_t = clock();
    printf("Run Time: %fs\n", (double)(finish_t - start_t) / CLOCKS_PER_SEC);
    return 0;
}