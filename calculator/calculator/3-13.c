#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<string.h>


double Add(double x, double y) {
    return x + y;
}

double Sub(double x, double y) {
    return x - y;
}

double Mul(double x, double y) {
    return x * y;
}

double Div(double x, double y) {
    if (y == 0) {
        printf("除数不能为0\n");
        return 0;
    }
    return x / y;
}

long And(long x, long y) {
    return x & y;
}

long Or(long x, long y) {
    return x | y;
}

long Cpl(long x) {
    return ~x;
}

void ref() {
    for (int a = 3; a >= 0; a--) {
        printf("系统在%d秒后刷新\n", a);
        Sleep(1000);
    }
    system("cls");
}

void menu() {
    puts("1: 加法+\n"
        "2：减法-\n"
        "3：乘法*\n"
        "4：除法/\n"
        "5:按位与&\n"
        "6:按位或|\n"
        "7:按位取反\n"
        "0: 退出\n");
    puts("请输入数字");
}

void calc(double(*pf1)(double, double), long(*pf2)(long, long)) {
    double x = 0.0;
    double y = 0.0;
    long x2 = 0;
    long y2 = 0;
    double ret1 = 0.0;
    long ret2 = 0;
    int c = 0;
    printf("请输入数值：");
    if (pf1 != NULL) {
        scanf("%lf %lf", &x, &y);
        ret1 = pf1(x, y);
        printf("%lf\n", ret1);
    }
    else if (pf2 != NULL) {
        if (pf2 == Cpl) {
            scanf("%ld", &x2);
            ret2 = pf2(x2, 0); // 使用第二个参数为 0
            printf("%ld\n", ret2);
        }
        else {
            scanf("%ld %ld", &x2, &y2);
            ret2 = pf2(x2, y2);
            printf("%ld\n", ret2);
        }
    }
    else {
        printf("函数指针为空\n");
        return;
    }
    puts("请输入回车以继续程序");
    getchar();
    while ((c = getchar()) != ('\n')) {
        getchar();
    }
    system("cls");
}

int main() {
    int input = 0;
    do {
        menu();
        scanf("%d", &input);
        switch (input) {
        case 1:
            calc(Add, NULL);
            break;
        case 2:
            calc(Sub, NULL);
            break;
        case 3:
            calc(Mul, NULL);
            break;
        case 4:
            calc(Div, NULL);
            break;
        case 5:
            calc(NULL, And);
            break;
        case 6:
            calc(NULL, Or);
            break;
        case 7:
            calc(NULL, Cpl);
            break;

        case 0:
            break;
        default:
            printf("输入错误\n");
            ref();
        }
    } while (input != 0);

    return 0;
}
