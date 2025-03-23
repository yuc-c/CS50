#include<cs50.h>
#include<stdio.h>

// 四則運算 long 為支持更高位數

int main(void)
{
    long x = get_long("x: ");
    long y = get_long("y: ");

    double z = (double) x / (double) y;
    printf("%.20f\n",z);

}
