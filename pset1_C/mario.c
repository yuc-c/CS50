#include <cs50.h>
#include <stdio.h>

int get_size(void);
void print_grid(int n);

int main(void)
{
    // do-while 循環 取得網格大小
    int n = get_size();
    print_grid(n);
    // 打印網格
}


int get_size(void)
{
    int n ;
    do
    {
        n = get_int("Size: ");
    }
    while( n < 1 );
    return n;
}

void print_grid(int n)
{
    for( int i = 0 ; i < n ; i++)
    {
        for ( int j = 0 ; j < n ; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
