#include <cs50.h>
#include <stdio.h>
#include <string.h>

// 給予一個數組 搜尋 是否在數組內

int main(void)
{
    /*
    // 找數字
    // []={} 創建具有特定值的數組
    int numbers[] = {20, 500, 10, 5, 100, 1, 50};

    int n = get_int("Number: ");
    for (int i = 0; i < 7; i++)
    {
        if (numbers[i] == n)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;*/

    //
    string strings[] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};

    string s = get_string("String: ");
    for (int i = 0; i < 6; i++)
    {
        // 因為一般 if 找有無符合 只能比對字元 無法比對字串
        // 使用 strcmp (s1, s2) 比較 s1 s2 兩字串 相同則返回 0
        // 輸入的 s 與 strings[i] 字串相比
        if (strcmp (strings[i], s) == 0)
        {
            printf("Foung\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
