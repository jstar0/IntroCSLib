#include<stdio.h>
#include<time.h>
#include<math.h>

int main()
{
    clock_t start_t, finish_t;
    start_t = clock();
    double result = 0;
    //Output terms from 1 to 50.
    for(int i = 1; i < 51; i++)
    {
        result = (1 / sqrt(5)) * ((pow(((1 + sqrt(5)) / 2), i)) - (pow(((1 - sqrt(5)) / 2), i)));
        printf("F(%d)=%.0lf\n", i, result);
    }
    finish_t = clock();
    printf("Run Time: %fs\n", (double)(finish_t - start_t) / CLOCKS_PER_SEC);
    return 0;
}