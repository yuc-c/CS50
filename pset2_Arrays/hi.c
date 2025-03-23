#include <stdio.h>
#include <cs50.h>

//字串、字元串

int main(void)
{
    // 方法一
    // char c1 = 'H';
    // char c2 = 'I';
    // char c3 = '!';

    // printf("%i %i %i\n", c1, c2, c3); // %c 為單一字元

    // 方法二
    // string s = "HI!";
    // string t = "BYE!";
    // printf("%s\n",s); // %s 為字串
    // printf("%c%c%c\n", s[0], s[1], s[2]); // %c s字串裡 0,1,2字元
    // printf("%s\n",t);

    //方法三
    string words[2];
    words[0] = "HI!";
    words[1] = "BYE!";

    printf("%c%c%c\n", words[0][0], words[0][1], words[0][2]);
    printf("%s\n", words[1]);
}
