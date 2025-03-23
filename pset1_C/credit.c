#include <cs50.h>
#include <stdio.h>

// 作業 輸入卡號 檢測為哪種卡 或 非卡號

int over(int n);

int main(void)
{
    long numbers;
    do
    {
        numbers = get_long("Number: ");
    }
    while (numbers < 0);

// visa 13位
    if (numbers > 3999999999999 && numbers < 5000000000000)
    {
        int thirteen = 0;
        while (numbers > 999999999999)
        {
            thirteen++;
            numbers = numbers - 1000000000000;
        }

        int twelve = 0;
        while (numbers > 99999999999)
        {
            twelve++;
            numbers = numbers - 100000000000;
        }

        int eleven = 0;
        while (numbers > 9999999999)
        {
            eleven++;
            numbers = numbers - 10000000000;
        }

        int ten = 0;
        while (numbers > 999999999)
        {
            ten++;
            numbers = numbers - 1000000000;
        }

        int nine = 0;
        while (numbers > 99999999)
        {
            nine++;
            numbers = numbers - 100000000;
        }

        int eight = 0;
        while (numbers > 9999999)
        {
            eight++;
            numbers = numbers - 10000000;
        }

        int seven = 0;
        while (numbers > 999999)
        {
            seven++;
            numbers = numbers - 1000000;
        }

        int six = 0;
        while (numbers > 99999)
        {
            six++;
            numbers = numbers - 100000;
        }

        int five = 0 ;
        while(numbers>9999)
        {
            five++ ;
            numbers = numbers - 10000 ;
        }

        int four = 0 ;
        while(numbers>999)
        {
            four++ ;
            numbers = numbers - 1000 ;
        }

        int three = 0 ;
        while(numbers>99)
        {
            three++ ;
            numbers = numbers - 100 ;
        }

        int two = 0 ;
        while(numbers>9)
        {
            two++ ;
            numbers = numbers - 10 ;
        }

        int one = 0 ;
        while(numbers>0)
        {
            one++ ;
            numbers = numbers - 1 ;
        }


        int secondlast ;
        secondlast = over(two) + over(four) + over(six) + over(eight) + over(ten) + over(twelve) ;

        int sum ;
        sum = secondlast + one + three + five + seven + nine + eleven + thirteen ;

        int remainder;
        remainder = sum % 10 ;

        if(remainder == 0)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }

    }

// visa 16位
    else if(numbers>3999999999999999 && numbers<5000000000000000)
    {
        int sixteen = 0 ;
        while(numbers>999999999999999)
        {
            sixteen++ ;
            numbers = numbers - 1000000000000000 ;
        }

        int fifteen = 0 ;
        while(numbers>99999999999999)
        {
            fifteen++ ;
            numbers = numbers - 100000000000000 ;
        }

        int fourteen = 0 ;
        while(numbers>9999999999999)
        {
            fourteen++ ;
            numbers = numbers - 10000000000000 ;
        }

        int thirteen = 0 ;
        while(numbers>999999999999)
        {
            thirteen++ ;
            numbers = numbers - 1000000000000 ;
        }

        int twelve = 0 ;
        while(numbers>99999999999)
        {
            twelve++ ;
            numbers = numbers - 100000000000 ;
        }

        int eleven = 0 ;
        while(numbers>9999999999)
        {
            eleven++ ;
            numbers = numbers - 10000000000 ;
        }

        int ten = 0 ;
        while(numbers>999999999)
        {
            ten++ ;
            numbers = numbers - 1000000000 ;
        }

        int nine = 0 ;
        while(numbers>99999999)
        {
            nine++ ;
            numbers = numbers - 100000000 ;
        }

        int eight = 0 ;
        while(numbers>9999999)
        {
            eight++ ;
            numbers = numbers - 10000000 ;
        }

        int seven = 0 ;
        while(numbers>999999)
        {
            seven++ ;
            numbers = numbers - 1000000 ;
        }

        int six = 0 ;
        while(numbers>99999)
        {
            six++ ;
            numbers = numbers - 100000 ;
        }

        int five = 0 ;
        while(numbers>9999)
        {
            five++ ;
            numbers = numbers - 10000 ;
        }

        int four = 0 ;
        while(numbers>999)
        {
            four++ ;
            numbers = numbers - 1000 ;
        }

        int three = 0 ;
        while(numbers>99)
        {
            three++ ;
            numbers = numbers - 100 ;
        }

        int two = 0 ;
        while(numbers>9)
        {
            two++ ;
            numbers = numbers - 10 ;
        }

        int one = 0 ;
        while(numbers>0)
        {
            one++ ;
            numbers = numbers - 1 ;
        }


        int secondlast ;
        secondlast = over(two) + over(four) + over(six) + over(eight) + over(ten) + over(twelve) + over(fourteen) + over(sixteen) ;

        int sum ;
        sum = secondlast + one + three + five + seven + nine + eleven + thirteen + fifteen ;

        int remainder;
        remainder = sum % 10 ;

        if(remainder == 0)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }

    }
//MASTERCARD 16位
    else if(numbers>5099999999999999 && numbers<5600000000000000)
    {
        int sixteen = 0 ;
        while(numbers>999999999999999)
        {
            sixteen++ ;
            numbers = numbers - 1000000000000000 ;
        }

        int fifteen = 0 ;
        while(numbers>99999999999999)
        {
            fifteen++ ;
            numbers = numbers - 100000000000000 ;
        }

        int fourteen = 0 ;
        while(numbers>9999999999999)
        {
            fourteen++ ;
            numbers = numbers - 10000000000000 ;
        }

        int thirteen = 0 ;
        while(numbers>999999999999)
        {
            thirteen++ ;
            numbers = numbers - 1000000000000 ;
        }

        int twelve = 0 ;
        while(numbers>99999999999)
        {
            twelve++ ;
            numbers = numbers - 100000000000 ;
        }

        int eleven = 0 ;
        while(numbers>9999999999)
        {
            eleven++ ;
            numbers = numbers - 10000000000 ;
        }

        int ten = 0 ;
        while(numbers>999999999)
        {
            ten++ ;
            numbers = numbers - 1000000000 ;
        }

        int nine = 0 ;
        while(numbers>99999999)
        {
            nine++ ;
            numbers = numbers - 100000000 ;
        }

        int eight = 0 ;
        while(numbers>9999999)
        {
            eight++ ;
            numbers = numbers - 10000000 ;
        }

        int seven = 0 ;
        while(numbers>999999)
        {
            seven++ ;
            numbers = numbers - 1000000 ;
        }

        int six = 0 ;
        while(numbers>99999)
        {
            six++ ;
            numbers = numbers - 100000 ;
        }

        int five = 0 ;
        while(numbers>9999)
        {
            five++ ;
            numbers = numbers - 10000 ;
        }

        int four = 0 ;
        while(numbers>999)
        {
            four++ ;
            numbers = numbers - 1000 ;
        }

        int three = 0 ;
        while(numbers>99)
        {
            three++ ;
            numbers = numbers - 100 ;
        }

        int two = 0 ;
        while(numbers>9)
        {
            two++ ;
            numbers = numbers - 10 ;
        }

        int one = 0 ;
        while(numbers>0)
        {
            one++ ;
            numbers = numbers - 1 ;
        }

        int secondlast ;
        secondlast = over(two) + over(four) + over(six) + over(eight) + over(ten) + over(twelve) + over(fourteen) + over(sixteen) ;

        int sum ;
        sum = secondlast + one + three + five + seven + nine + eleven + thirteen + fifteen ;

        int remainder;
        remainder = sum % 10 ;

        if(remainder == 0)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }

    }

// AMEX 15位 37開頭
    else if(numbers > 369999999999999 && numbers < 380000000000000)
    {
        int fifteen = 0 ;
        while(numbers>99999999999999)
        {
            fifteen++ ;
            numbers = numbers - 100000000000000 ;
        }

        int fourteen = 0 ;
        while(numbers>9999999999999)
        {
            fourteen++ ;
            numbers = numbers - 10000000000000 ;
        }

        int thirteen = 0 ;
        while(numbers>999999999999)
        {
            thirteen++ ;
            numbers = numbers - 1000000000000 ;
        }

        int twelve = 0 ;
        while(numbers>99999999999)
        {
            twelve++ ;
            numbers = numbers - 100000000000 ;
        }

        int eleven = 0 ;
        while(numbers>9999999999)
        {
            eleven++ ;
            numbers = numbers - 10000000000 ;
        }

        int ten = 0 ;
        while(numbers>999999999)
        {
            ten++ ;
            numbers = numbers - 1000000000 ;
        }

        int nine = 0 ;
        while(numbers>99999999)
        {
            nine++ ;
            numbers = numbers - 100000000 ;
        }

        int eight = 0 ;
        while(numbers>9999999)
        {
            eight++ ;
            numbers = numbers - 10000000 ;
        }

        int seven = 0 ;
        while(numbers>999999)
        {
            seven++ ;
            numbers = numbers - 1000000 ;
        }

        int six = 0 ;
        while(numbers>99999)
        {
            six++ ;
            numbers = numbers - 100000 ;
        }

        int five = 0 ;
        while(numbers>9999)
        {
            five++ ;
            numbers = numbers - 10000 ;
        }

        int four = 0 ;
        while(numbers>999)
        {
            four++ ;
            numbers = numbers - 1000 ;
        }

        int three = 0 ;
        while(numbers>99)
        {
            three++ ;
            numbers = numbers - 100 ;
        }

        int two = 0 ;
        while(numbers>9)
        {
            two++ ;
            numbers = numbers - 10 ;
        }

        int one = 0 ;
        while(numbers>0)
        {
            one++ ;
            numbers = numbers - 1 ;
        }

        int secondlast ;
        secondlast = over(two) + over(four) + over(six) + over(eight) + over(ten) + over(twelve) + over(fourteen) ;

        int sum ;
        sum = secondlast + one + three + five + seven + nine + eleven + thirteen + fifteen ;

        int remainder;
        remainder = sum % 10 ;

        if(remainder == 0)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }

    }

// AMEX 15位 34開頭
    else if(numbers > 339999999999999 && numbers < 350000000000000)
    {
        int fifteen = 0 ;
        while(numbers>99999999999999)
        {
            fifteen++ ;
            numbers = numbers - 100000000000000 ;
        }

        int fourteen = 0 ;
        while(numbers>9999999999999)
        {
            fourteen++ ;
            numbers = numbers - 10000000000000 ;
        }

        int thirteen = 0 ;
        while(numbers>999999999999)
        {
            thirteen++ ;
            numbers = numbers - 1000000000000 ;
        }

        int twelve = 0 ;
        while(numbers>99999999999)
        {
            twelve++ ;
            numbers = numbers - 100000000000 ;
        }

        int eleven = 0 ;
        while(numbers>9999999999)
        {
            eleven++ ;
            numbers = numbers - 10000000000 ;
        }

        int ten = 0 ;
        while(numbers>999999999)
        {
            ten++ ;
            numbers = numbers - 1000000000 ;
        }

        int nine = 0 ;
        while(numbers>99999999)
        {
            nine++ ;
            numbers = numbers - 100000000 ;
        }

        int eight = 0 ;
        while(numbers>9999999)
        {
            eight++ ;
            numbers = numbers - 10000000 ;
        }

        int seven = 0 ;
        while(numbers>999999)
        {
            seven++ ;
            numbers = numbers - 1000000 ;
        }

        int six = 0 ;
        while(numbers>99999)
        {
            six++ ;
            numbers = numbers - 100000 ;
        }

        int five = 0 ;
        while(numbers>9999)
        {
            five++ ;
            numbers = numbers - 10000 ;
        }

        int four = 0 ;
        while(numbers>999)
        {
            four++ ;
            numbers = numbers - 1000 ;
        }

        int three = 0 ;
        while(numbers>99)
        {
            three++ ;
            numbers = numbers - 100 ;
        }

        int two = 0 ;
        while(numbers>9)
        {
            two++ ;
            numbers = numbers - 10 ;
        }

        int one = 0 ;
        while(numbers>0)
        {
            one++ ;
            numbers = numbers - 1 ;
        }

        int secondlast ;
        secondlast = over(two) + over(four) + over(six) + over(eight) + over(ten) + over(twelve) + over(fourteen) ;

        int sum ;
        sum = secondlast + one + three + five + seven + nine + eleven + thirteen + fifteen ;

        int remainder;
        remainder = sum % 10 ;

        if(remainder == 0)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }

    }

// 非 上述三種條件
    else
    {
        printf("INVALID\n");
    }
}




int over(int n)
{
    if( n >= 5 )
    {
        n = n*2 - 10 + 1 ;
    }
    else
    {
        n = n*2 ;
    }
    return n ;
}

