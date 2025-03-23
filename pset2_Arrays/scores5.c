#include <cs50.h>
#include <stdio.h>

// 優化 數組 函數

// Constant 持續 維持常數N
const int N = 3;

// Prototype 原型
float average(int length,int array[]);

int main(void)
{
    // Get scores 常數3筆資料 0,1,2
    int scores[N];
    for ( int i = 0; i < N; i++)
    {
        scores[i] = get_int("Score: ");
    }
    // Print Average
    printf("Average: %f\n",average(N,scores));
}

// length 長度 array陣列依序由輸入的三組數字 代表0,1,2 
float average(int length,int array[]) // 定義函數
{
    // Calculate average 計算平均值
    int sum = 0;
    for ( int i = 0; i < length; i++)
    {
        sum += array[i]; //一個一個加總
    }
    return sum / (float) length; //平均(浮點數) length = 3.0
}
