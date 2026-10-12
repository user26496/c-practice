#include <stdio.h>
#include <stdlib.h>

void matmul(const float *A, const float *B, float *C, int M, int N, int K);
int main()
{
    int M = 3, K = 4, N = 2;
    float *A = (float *)malloc(sizeof(float) * M * K);
    float *B = (float *)malloc(sizeof(float) * K * N);
    float *C = (float *)malloc(sizeof(float) * M * N);
    for (int i = 0; i < M * K; i++)
        A[i] = (float)(i + 1);
    for (int i = 0; i < K * N; i++)
        B[i] = (float)(i + 1);
    matmul(A, B, C, M, N, K);

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%6.1f ", C[i * N + j]);
        }
        printf("\n");
    }

    free(A);
    free(B);
    free(C);
    return 0;
}
void matmul(const float *A, const float *B, float *C, int M, int N, int K)
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            float sum = 0;
            for (int k = 0; k < K; k++)
            {
                sum += A[i * K + k] * B[k * N + j];
            }
            C[i * N + j] = sum;
        }
    }
}
// __global__ void matmul(const float *A, const float *B, float *C, int M, int N, int K)
// {
//     int na = blockIdx.x * blockDim.x + threadIdx.x;
//     int nb = blockIdx.y * blockDim.y + threadIdx.y;
//     int nc = blockIdx.z * blockDim.z + threadIdx.z;
//     C[na * N + nb] = A[na * K + nc] * B[nc * N + nb];
// }