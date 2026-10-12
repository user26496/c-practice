#include <stdio.h>
#include <stdlib.h>

void mean_and_var(const float *x, int N, float *out_mean, float *out_var);
int main()
{
    int N = 10;
    float *x = (float *)malloc(sizeof(float) * N);
    for (int i = 0; i < N; i++)
        x[i] = (float)(i + 1);
    float mean, var;
    mean_and_var(x, N, &mean, &var);
    free(x);
    printf("mean: %f, var: %f\n", mean, var);
    return 0;
}

void mean_and_var(const float *x, int N, float *out_mean, float *out_var)
{
    float sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += x[i];
    }
    *out_mean = sum / N;
    float sum_sq = 0;
    for (int i = 0; i < N; i++)
    {
        sum_sq += (x[i] - *out_mean) * (x[i] - *out_mean);
    }
    *out_var = sum_sq / N;
}
