#include <stdio.h>

// 交換數值

void swap(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    swap(&x, &y); // 傳遞地址交換
    printf("x is %i, y is %i\n", x, y);
}

// 利用tmp臨時變數 讓a跟b交換
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
