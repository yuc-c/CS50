#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 作業 替換密碼
int rotate(char c, string key);

int main(int argc, string argv[])
{
    // 先確保只有一字串 argv[1]
    if(argc == 2)
    {
        // 是否含有26個字元
        if (strlen(argv[1]) != 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1; // 必須包含26個字元 傳回錯誤
        }

        // 有26個字元後 確認每一個字元
        // 檢查字元有無非字母存在
        for (int i = 0; i < 26; i++)
        {
            if (!isalpha(argv[1][i])) // 有一字元為非英文字母
            {
                printf("Key must only contain alphabetic characters.\n");
                return 1; // 輸入字串非字母 傳回錯誤
            }
            for (int j = i + 1; j < 26; j++)
            {
                if (argv[1][i] == argv[1][j])
                {
                    printf("Key must not contain repeated characters.\n");
                    return 1; // 輸入字串有重複字母 傳回錯誤
                }
            }
        }
        // 先讓 key 為命令字串
        string key = argv[1];
        // 詢問輸入字串
        string input = get_string("plaintext:  ");
        // 輸出字串
        printf("ciphertext: ");
        // 循環字元去轉換 ； k 為 輸入的字串字元個數
        for(int k = 0; k < strlen(input); k++)
        {
            printf("%c",rotate((input[k]),key));
        }
        printf("\n");
    }
    else // 多字串 或 無字串
    {
        printf("Usage: %s key\n",argv[0]);
        return 1; // 傳回錯誤
    }
}

int rotate(char c, string key)
{
    // 指數index 原字元與轉換字元差距
    int index = tolower(c)-'a';
    // 轉換為新字元
    char new_char = key[index];
    // 如果是小寫 轉換完 依舊為小寫
    if (c >= 'a' && c <= 'z')
    {
        c = tolower(new_char);
        return c;
    }
    // 如果是大寫 轉換完 依舊為大寫
    else if (c >= 'A' && c <= 'Z')
    {
        c = toupper(new_char);
        return c;
    }
    return c;
}

