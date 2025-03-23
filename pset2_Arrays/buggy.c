#include <stdio.h>
#include <cs50.h>

// 利用printf 回推 測試bug

void print_column(int h);

int main(void)
{
    // for(int i = 0; i < 3; i++)
    // {
    //     // printf("i is %d\n", i); 用來測試bug
    //     printf("#\n");
    // }

    int h = get_int("Height: ");
    print_column(h);
}

void print_column(int h)
{
    for(int i = 0; i <= h; i++)
    {
        printf("#\n");
    }
}
