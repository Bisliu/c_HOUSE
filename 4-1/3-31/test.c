#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>

#define MAX_SIZE 10
double hanglieshi(int n, double arr[MAX_SIZE][MAX_SIZE])
{
    double resault = 0;
    double xiaoshuzu[MAX_SIZE][MAX_SIZE];

    if (n == 1) 
    {
        return arr[0][0];
    }
    else if (n == 2) 
    {
        return arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0];
    }
    else
    {
        for (int c = 0; c < n; c++) 
        {
            int xiaoshuzu_xuhao = 0;
            for (int i = 1; i < n; i++) 
            {
                int xiaoshuzu_lie_xuhao = 0; 
                for (int j = 0; j < n; j++) 
                {
                    if (j == c) continue;
                    xiaoshuzu[xiaoshuzu_xuhao][xiaoshuzu_lie_xuhao] = arr[i][j];
                    xiaoshuzu_lie_xuhao++;
                }
                xiaoshuzu_xuhao++;
            }
            resault += pow(-1, c) * arr[0][c] * hanglieshi(n - 1, xiaoshuzu);
        }
    }
    return resault;
}

int main() {
    int n;
    printf("请输入方阵的大小：");
    scanf("%d", &n);
    double arr[MAX_SIZE][MAX_SIZE];
    printf("请输入矩阵的元素：\n");
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            scanf("%lf", &arr[i][j]);
        }
    }

    double jieguo = hanglieshi(n, arr);
    printf("行列式的值为：%.2lf\n", jieguo);

    return 0;
}
