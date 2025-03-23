#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 利用if 跟 for 循環 增加嚴謹性 減少出錯的可能

int main(void)
{
    char *s = get_string("s: ");

    char *t = malloc(strlen(s) + 1); // 給予4個字節的內存 並將第一個字節的地址存儲在t中 +1個空字符
    if (t == NULL)  // 確保沒有的時候不會存儲
    {
        return 1;
    }

    strcpy(t, s); // 縮減以下註解的

    /*
    for (int i = 0, n = strlen(s); i <= n; i++)
    {
        t[i] = s[i];
    }
    */

    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf("s: %s\n", s);
    printf("t: %s\n", t);

    free(t); // 不再使用t 釋放內存 與 malloc 相反
}
