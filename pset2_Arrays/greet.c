#include <cs50.h>
#include <stdio.h>

// 當main(void) 不使用void 的輸入方式

int main(int argc, string argv[])
{
    // if(argc == 2)
    // {
    //     printf("hello, %s\n", argv[1]);
    // }
    // else
    // {
    //     printf("hello, world\n");
    // }
    for ( int i = 1; i < argc; i++)
    {
        printf("%s\n",argv[i]);
    }
}
