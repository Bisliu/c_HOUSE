#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>.h>
#include<string.h>


int Add(int x, int y)
{
    return x + y;
}

int Sub(int x, int y)
{
    return x - y;
}

int Mul(int x, int y)
{
    return x * y;
}

int Div(int x, int y)
{
    return x / y;
}

void ref()
{
    for (int a = 3; a >= 0; a--)
    {
        printf("系统在%d秒后刷新\n", a);
        Sleep(1000);
    }
    system("cls");
}

void meau()
{
    puts("1: 加法\n"
        "2：减法\n"
        "3：乘法\n"
        "4：除法\n"
        "0: 退出\n");
    puts("请输入数字");
}

void calc(int(*pf)(int, int))
{
    int x = 0;
    int y = 0;
    int ret = 0;
    int c = 0;
    printf("请输入数值：");
    scanf("%d %d", &x, &y);
    ret = pf(x, y);
    printf("%d\n", ret);
    puts("请输入回车以继续程序");
    getchar();
    while ((c = getchar()) != ('\n'))
    {
        getchar();
    }
    system("cls");
}

int main()
{
    int input = 0;
    do
    {
        meau();
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            calc(Add); break;
        case 2:
            calc(Sub); break;
        case 3:
            calc(Mul); break;
        case 4:
            calc(Div); break;
        case 0:
            break;
        default:
            printf("输入错误\n");
            ref();
        }
    } while (input);
    return 0;
}