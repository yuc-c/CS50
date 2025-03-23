#include <cs50.h>
#include <stdio.h>

// return 0 、 return 1 利用 echo $? 確認上次執行的返回值

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Missing command-line argument\n");
        return 1;
    }
    printf("hello, %s\n", argv[1]);
    return 0;
}
