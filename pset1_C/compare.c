#include <cs50.h>
#include <stdio.h>

// if 與 else if 、 else 的用法

int main(void)
{
    int x = get_int("what's x?");
    int y = get_int("what's y?");

    if (x < y)
    {
        printf("x is less than y\n");
    }
    else if (x > y)
    {
        printf("x is greater than y\n");
    }
    else
    {
        printf("x is equal to y\n");
    }
}
