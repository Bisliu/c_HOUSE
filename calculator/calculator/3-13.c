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
        printf("ϵͳ��%d���ˢ��\n", a);
        Sleep(1000);
    }
    system("cls");
}

void meau()
{
    puts("1: �ӷ�\n"
        "2������\n"
        "3���˷�\n"
        "4������\n"
        "0: �˳�\n");
    puts("����������");
}

void calc(int(*pf)(int, int))
{
    int x = 0;
    int y = 0;
    int ret = 0;
    int c = 0;
    printf("��������ֵ��");
    scanf("%d %d", &x, &y);
    ret = pf(x, y);
    printf("%d\n", ret);
    puts("������س��Լ�������");
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
            printf("�������\n");
            ref();
        }
    } while (input);
    return 0;
}