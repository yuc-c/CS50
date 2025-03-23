#include <cs50.h>
#include <stdio.h>
#include <string.h>

// 兩個字串 即使 內容相同 但存在不同地址

int main(void)
{
    /*
    char *s = get_string("s: ");
    char *t = get_string("t: ");

    if (s == t) // 字串存儲的地址不同
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
    */

    char *s = get_string("s: ");
    char *t = get_string("t: ");

    printf("%p\n", s);
    printf("%p\n", t);

    if (strcmp(s , t) == 0) // 利用 strcmp 字串呈現後去比較 而非比較地址
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
}
