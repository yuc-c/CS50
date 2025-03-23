#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

//作業 拼字遊戲

int compute_score(string words);
int POINT[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};


int main(void)
{
    // Player1、Player2輸入字串
    string words1 = get_string("Player 1: ");
    string words2 = get_string("Player 2: ");

    //計算得分
    int score1 = compute_score(words1);
    int score2 = compute_score(words2);

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if(score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

}

int compute_score(string words)
{
    int score = 0;
    // 先循環 輸入幾個字元 循環幾次
    for( int i = 0; i < strlen(words); i++)
    {
        if (words[i] >= 'a' && words[i] <= 'z')
        {
            score += POINT[words[i] - 'a'];
        }
        else if (words[i] >= 'A' && words[i] <= 'Z')
        {
            score += POINT[words[i] - 'A'];
        }
    }
    return score;
}
