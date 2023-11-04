#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define MAXN 100001

float A[MAXN] = {};
float temp;
int left, right;
float p = 0;

void quicksort(int lo, int hi);
int partition(float p, int lo, int hi);
float pivot(int lo, int hi);

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

void quicksort(int lo, int hi)
{
    if(lo < hi)
    {
        p = pivot(lo, hi);
        partition(p, lo, hi);
        quicksort(lo, left - 1);
        quicksort(right + 1, hi);
    }
}

int partition(float p, int lo, int hi)
{
    left = lo;
    right = hi;
    int i = lo;

    while(i <= right)
    {
        if(A[i] < p)
        {
            temp = A[i];
            A[i] = A[left];
            A[left] = temp;
            left++;
            i += 1;
        }
        else if(A[i] > p)
        {
            temp = A[i];
            A[i] = A[right];
            A[right] = temp;
            right--;
        }
        else {
            i++;
        }
    }
    return 0;
}

float pivot(int lo, int hi)
{
    int mid = ((hi - lo) / 2) + lo;
    if(A[mid] < A[lo]) {
        temp = A[lo];
        A[lo] = A[mid];
        A[mid] = temp;
    }
    if(A[hi] < A[lo]) {
        temp = A[lo];
        A[lo] = A[hi];
        A[hi] = temp;
    }
    if(A[mid] < A[hi]) {
        temp = A[hi];
        A[hi] = A[mid];
        A[mid] = temp;
    }
    return A[hi];
}
