#include <cs50.h>
#include <stdio.h>
// ^^載入資料庫

// 基礎用法

int main(void)
{
    string first = get_string("what's your first name?\n");
    string last = get_string("what's your last name?\n");
    printf("hello, %s %s !\n",first,last);
}
// %s為指令 輸入answer後依照後面順序填入
