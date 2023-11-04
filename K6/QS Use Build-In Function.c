#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAXN 100001

int cmp (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b ); //从小到大的实现方法
    //return ( *(int*)b - *(int*)a ); //从大到小的实现方法
}

int main()
{
    float A[MAXN] = {};
    srand((unsigned) clock());
    for(int i = 0; i < MAXN; i++)
    {
        A[i] = (double) rand() / 100000 + rand();
    }

    clock_t start_t, finish_t;
    start_t = clock();

    qsort(A, MAXN, sizeof(A[0]), cmp);

    finish_t = clock();

    FILE *fp = NULL;

    fp = fopen("./log_c.txt", "w+");

    for(int i = 0; i < MAXN; i++)
    {
        fprintf(fp, "%f, ", A[i]);
        printf("%f, ", A[i]);
    }

    fclose(fp);

    printf("\nRun Time: %fs\n", (double)(finish_t - start_t) / CLOCKS_PER_SEC);

}
