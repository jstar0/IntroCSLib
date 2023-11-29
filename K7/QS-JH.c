#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define MAXN 100001

float A[MAXN] = {};
float temp;
int p = 0;

void quicksort(int l, int r);

int main()
{
    srand((unsigned) clock());
    for(int i = 0; i < MAXN; i++)
    {
        A[i] = (double) rand() / 100000 + rand();
    }

    clock_t start_t, finish_t;
    start_t = clock();
    quicksort(0, 100000);
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

void quicksort(int l, int r)
{
    float mid = A[l];
    int i = l, j = r;
    while (i <= j)
    {
        while (A[i] < mid \
        && i <= j) i++;
        while (A[j] > mid \
        && i <= j) j--;
        if (i <= j) {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i++; j--;
        }
    }
    if (l < j)  quicksort(l, j);
    if (i < r)  quicksort(i, r);
}