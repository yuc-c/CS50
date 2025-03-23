#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 作業 凱撒密碼

int rotate(char c, int n);

int main(int argc, string argv[])
{
    if(argc == 2)
    {
        // while 循環 偵測字串是否有非數字
        int i = 0;
        while (argv[1][i] != '\0')
        {
            if(!isdigit(argv[1][i]))
            {
                printf("Usage: %s key\n",argv[0]);
                return 1; // 傳回錯誤
            }
            i++;
        }

        // 確認好詢問字串
        string plaintext = get_string("plaintext:  ");

        // 根據金鑰轉換
        printf("ciphertext: ");

        // 循環 plaintext 每一個字元 並進行金鑰轉換
        // 利用 atoi 將 string 轉換為 int 為一開始輸入的金鑰
        int n = atoi(argv[1]);
        for(int j = 0; j < strlen(plaintext); j++)
        {
            printf("%c",rotate(plaintext[j],n));
        }
        printf("\n");
    }
    else
    {
        printf("Usage: %s key\n",argv[0]);
        return 1; // 傳回錯誤
    }
}

int rotate(char c, int n)
{
    if(c >= 'a' && c <= 'z')
    {
        c = ((c - 'a' + n) % 26) + 'a';
        return c;
    }
    else if(c >= 'A' && c <= 'Z')
    {
        c = ((c - 'A' + n) % 26) + 'A';
        return c;
    }
    return c;
}

