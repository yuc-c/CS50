#include <cs50.h>
#include <stdio.h>

// 作業 輸入cents 輸出 最少需幾枚硬幣

int main(void)
{
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while( cents < 0);

    int quarters = 0;
    while( cents >= 25 )
    {
        quarters++;
        cents = cents - 25;

    }

    int dimes = 0;
    while( cents >= 10 )
    {
        dimes++;
        cents = cents - 10;
    }


    int nickels = 0;
    while( cents >= 5 )
    {
        nickels++;
        cents = cents - 5;
    }


    int pennies = 0;
    while( cents >= 1 )
    {
        pennies++;
        cents = cents - 1;
    }

    int coin;

    coin = quarters + dimes + nickels + pennies ;

    printf("%d\n",coin);
}

