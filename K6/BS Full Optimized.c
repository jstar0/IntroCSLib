#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define MAXN 100001

float A[MAXN] = {};

void bubblesort(float A[]);

int main()
{
    srand((unsigned) clock());
    for(int i = 0; i < MAXN; i++)
    {
        A[i] = (float) rand() / 100000 + rand();
    }

    clock_t start_t, finish_t;
    start_t = clock();
    bubblesort(A);
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

void bubblesort(float A[])
{
    int n = MAXN;
    int i, newn;
    float temp;
    do
    {
        int newn = 0;
        for(i = 1; i < n; i++)
        {
            if(A[i - 1] > A[i])
            {
                temp = A[i - 1];
                A[i - 1] = A[i];
                A[i] = temp;
                newn = i;
            }
        }
        n = newn;
    }   while (n > 1);
}