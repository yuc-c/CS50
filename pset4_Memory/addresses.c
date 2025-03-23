#include <cs50.h>
#include <stdio.h>

// 指針 *p
// string = char *

int main(void)
{

    // n信箱裡面有50，n地址是0X123，p信箱裡有指向n的地址
    int n = 50;
    int *p = &n; // 定義 從p可以到達n的地址 (*p = &n)
    printf("%i\n", *p); // %i打印整數(可接受不同進制) %p打印地址

    char *s = "HI!";
    printf("%p\n", s);     // 字符串的地址 就是第0個字元地址 至\0結束
    printf("%p\n", &s[0]); 
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);

    printf("%c\n", *s); // 打印字元
    printf("%c\n", *(s + 1));
    printf("%c\n", *(s + 2));

    printf("%s\n", s + 1); // 打印字串 從 0x123 + 1 = 0x124 故為字串的第二字元開始
}
