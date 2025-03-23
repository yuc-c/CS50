#include <cs50.h>
#include <stdio.h>

// 將 get_int 拆解

int main(void)
{
    int n;
    printf("n: ");
    scanf("%i", &n); // printf 為打印 相反 scanf為讀取  讀取輸入的地址
    printf("n: %i\n", n);

    /* // 上述為 get_int 拿掉後的呈現
    int n = get_int("n: ");
    printf("n: %i\n", n);
    */

    char s[4];
    printf("s: ");
    scanf("%s", s); // 因為本身就為地址 故不用&
    printf("s: %s\n", s);
}
