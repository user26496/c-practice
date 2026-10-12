#include <stdio.h>
#include <stdlib.h>

float get_elem(const float *tensor,
               int b, int t, int nh, int hs,
               int B, int T, int NH, int HS);

void set_elem(float *tensor,
              int b, int t, int nh, int hs,
              int B, int T, int NH, int HS,
              float val);

int main()
{
    int B = 2, T = 3, NH = 2, HS = 4;
    int total = B * T * NH * HS; // 应该 = 48
    float *tensor = (float *)malloc(total * sizeof(float));

    // 把 tensor 全初始化为 0
    for (int i = 0; i < total; i++)
        tensor[i] = 0.0f;

    // 写几个值
    set_elem(tensor, 0, 0, 0, 0, B, T, NH, HS, 1.0f); // 位置 0
    set_elem(tensor, 0, 0, 0, 3, B, T, NH, HS, 2.0f); // 位置 3
    set_elem(tensor, 1, 2, 1, 3, B, T, NH, HS, 9.0f); // 位置 47 (最后一个)

    // 读出来验证
    printf("tensor[0,0,0,0] = %.1f\n", get_elem(tensor, 0, 0, 0, 0, B, T, NH, HS)); // 期望 1.0
    printf("tensor[0,0,0,3] = %.1f\n", get_elem(tensor, 0, 0, 0, 3, B, T, NH, HS)); // 期望 2.0
    printf("tensor[1,2,1,3] = %.1f\n", get_elem(tensor, 1, 2, 1, 3, B, T, NH, HS)); // 期望 9.0

    free(tensor);

    return 0;
}

float get_elem(const float *tensor, int b, int t, int nh, int hs, int B, int T, int NH, int HS)
{
    int offset = b * (T * NH * HS) + t * (NH * HS) + nh * HS + hs;
    return tensor[offset];
}

void set_elem(float *tensor, int b, int t, int nh, int hs, int B, int T, int NH, int HS, float val)
{
    int offset = b * (T * NH * HS) + t * (NH * HS) + nh * HS + hs;
    tensor[offset] = val;
}