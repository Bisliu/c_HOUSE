#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include<windows.h>

void GAME();
void guess(int a, int start, int end);

void GAME()
{
    int m = 0;
    int a = 0;
    printf("**************************\n");
    printf("******请选择游戏跨度******\n");
    printf("****1：很短   2：较短*****\n");
    printf("****3：较长   4：很长*****\n");
    printf("****5:自定义  6：游戏规则*\n");
    printf("****7：退出游戏 **********\n");
    printf("**************************\n");
    printf("请选择数字：");
    scanf("%d", &a);
    switch (a)
    {
    case 1:
        m = 10;
        break;
    case 2:
        m = 50;
        break;
    case 3:
        m = 100;
        break;
    case 4:
        m = 200;
        break;
    case 5:
        printf("请输入游戏跨度:");
        scanf("%d", &m);
        break;
    case 6:
        printf("这是多人游戏，通过输入数字缩小范围\n猜到数字的人将受到严峻的惩罚\n跨度表示游戏数字从0到多少\n");
        printf("输入0返回到游戏主菜单\n");
        char back[10];
        scanf("%s", back);
        if (strcmp(back, "0") == 0)
        {
            system("cls");
            GAME();
            return;
        }
        break;
    case 7:
        exit(0);
    default:
        printf("输入错误，请重新输入\n");
        for (int i = 3; i >= 0; i--)
        {
            Sleep(1000);
            printf("系统将在%d秒后重置\n", i);
        }
        system("cls");
        GAME();
    }
    system("cls");
    printf("************************\n");
    printf("************************\n");
    printf("********游戏开始********\n");
    printf("请输入1—%d之间的数字:", m);
    srand(time(NULL));
    a = rand() % m + 1;
    guess(a, 0, m);
}

void guess(int a, int start, int end)
{
    int n = 0;
    scanf("%d", &n);
    if (n != a)
    {
        if (n < a && n > start)
        {
            start = n;
            printf("请输入%d-%d之间的数字:", start, end);
            guess(a, start, end);
        }
        else if (n > a && n < end)
        {
            end = n;
            printf("请输入%d-%d之间的数字:", start, end);
            guess(a, start, end);
        }
        else
        {
            printf("输入错误，请重新输入:");
            guess(a, start, end);
        }
    }
    else
        system("cls");
    printf("GAME OVER\n");
}

int main()
{
    GAME();
    return 0;
}