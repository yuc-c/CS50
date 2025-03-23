#include <cs50.h>
#include <stdio.h>
#include <string.h>

// 循環 字串裡的字元 不為零時循環 為零時停止

int string_length(string s);

int main(void)
{
    string name = get_string("Name: ");
    int length = strlen(name);
    printf("%i\n", length);
}

int string_length(string s) //name 為字串 設為s
{
    int n = 0;
    while (s[n] != '\0')
    {
        n++;
    }
    return n; //return 回 n
}
