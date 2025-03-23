#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// 輸入不論大小寫 切換成大寫

int main(void)
{
    string s = get_string("Before: ");
    printf("After:  ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // if ( s[i] >= 'a' && s[i] <= 'z') //if 字元為小寫
        // {
        //     //Change s[i] to uppercase
        //     printf("%c", toupper(s[i])); // s[i] -32 切換成大寫
        // }
        // else
        // {
        //     //Just print s[i]
        //     printf("%c", s[i]);
        // }
        printf("%c",toupper(s[i]));
    }
    printf("\n");
}
