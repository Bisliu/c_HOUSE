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
    printf("******��ѡ����Ϸ���******\n");
    printf("****1���ܶ�   2���϶�*****\n");
    printf("****3���ϳ�   4���ܳ�*****\n");
    printf("****5:�Զ���  6����Ϸ����*\n");
    printf("****7���˳���Ϸ **********\n");
    printf("**************************\n");
    printf("��ѡ�����֣�");
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
        printf("��������Ϸ���:");
        scanf("%d", &m);
        break;
    case 6:
        printf("���Ƕ�����Ϸ��ͨ������������С��Χ\n�µ����ֵ��˽��ܵ��Ͼ��ĳͷ�\n��ȱ�ʾ��Ϸ���ִ�0������\n");
        printf("����0���ص���Ϸ���˵�\n");
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
        printf("�����������������\n");
        for (int i = 3; i >= 0; i--)
        {
            Sleep(1000);
            printf("ϵͳ����%d�������\n", i);
        }
        system("cls");
        GAME();
    }
    system("cls");
    printf("************************\n");
    printf("************************\n");
    printf("********��Ϸ��ʼ********\n");
    printf("������1��%d֮�������:", m);
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
            printf("������%d-%d֮�������:", start, end);
            guess(a, start, end);
        }
        else if (n > a && n < end)
        {
            end = n;
            printf("������%d-%d֮�������:", start, end);
            guess(a, start, end);
        }
        else
        {
            printf("�����������������:");
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