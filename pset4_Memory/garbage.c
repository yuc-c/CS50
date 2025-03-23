#include <stdio.h>

// 偵錯 valgrind ./memory

int main(void)
{
    int scores[1024];
    for (int i = 0; i < 1024; i++)
    {
        printf("%i\n", scores[i]);
    }
}
// 會呈現 1024 個隨機數字
