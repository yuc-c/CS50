#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

//作業2 閱讀程度分級

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    //詢問
    string text = get_string("Text: ");

    //計算字母數
    int letter = count_letters(text);
    //計算單字數
    int word = count_words(text);
    //計算句子數
    int sentences = count_sentences(text);
    //計算 Coleman-Liau 指數
    double index = 0;
    double L = ((double) letter / (double) word)*100;
    double S = ((double) sentences / (double) word)*100;
    index = 0.0588 * L - 0.296 * S - 15.8;
    /*
    printf("%d\n",letter);
    printf("%d\n",word);
    printf("%d\n",sentences);
    printf("%f\n",L);
    printf("%f\n",index);
    */

    //四捨五入後分級

    if (round(index) >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (round(index) < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n",(int)round(index));
    }

}

int count_letters(string text)
{
    // 算字母數，字串裡為大小寫A~Z則+1
    int letter = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            letter++;
        }
        else if (text[i] >= 'a' && text[i] <= 'z')
        {
            letter++;
        }
    }
    return letter;
}

int count_words(string text)
{
    // 算單字數，遇到空格+1
    int word = 1; // 結尾單字後面不會有空格
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            word++;
        }
    }
    return word;
}

int count_sentences(string text)
{
    // 算句子
    int sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}
