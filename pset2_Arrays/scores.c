#include <stdio.h>
#include <cs50.h>

// 數組

int main(void)
{
    const int N = 3; //設定常數固定為3
    int scores[N]; //定義數組
    for(int i = 0; i < N; i++)
    {
        scores[i] = get_int("Scores: "); //詢問常數次數 分數
    }

    // print average
    printf("Average: %f\n",(scores[0] + scores[1] + scores[2]) / (float) N); //數組相加後 / (浮點數) 常數 3

}
