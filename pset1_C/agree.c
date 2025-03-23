#include <cs50.h>
#include <stdio.h>

// if 與 else if 、 else 的用法

int main(void)
{
    char c = get_char("Do you agree?");

    if ( c == 'y'|| c =='Y' )
    // ||為或的意思
    {
        printf("Agreed.\n");
    }
    else if( c == 'n' || c=='N' )
    {
        printf("Not agreed.\n");
    }
}
