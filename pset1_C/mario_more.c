#include <cs50.h>
#include <stdio.h>

// 作業 循環、打印

void print_row(int n);

int main(void)
{
    int n ;
    do
    {
        n = get_int("Height: ");
    }
    while( n < 1 );
    print_row(n);
}


void print_row(int n)
{
    for( int i = 0 ; i < n ; i++)
    {
        for( int j = 0 ; j < n-i-1 ; j++)
        {
            printf(" ");
        }
        for (int j = 0 ; j < i+1 ; j++)
        {
            printf("#");
        }

        printf("  ");

        for (int j = 0 ; j < i+1 ; j++)
        {
            printf("#");
        }
    printf("\n");
    }
}
