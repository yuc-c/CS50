#include <math.h>
#include "helpers.h"

// Convert image to grayscale 灰階
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Take average of red, green, and blue 取紅、綠、藍的平均值
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            int gray = round((red + green + blue) / 3.0);  // round 四捨五入整數

            // Update pixel values 更新像素值

            image[i][j].rgbtRed = gray;
            image[i][j].rgbtGreen = gray;
            image[i][j].rgbtBlue = gray;
        }
    }
    return;
}

// Convert image to sepia 棕褐色
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels 循環遍歷所有像素
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
         {
            // Compute sepia values 計算棕褐色值

            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            // Update pixel with sepia values 使用棕褐色值更新像素
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            image[i][j].rgbtRed = sepiaRed;

            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            image[i][j].rgbtGreen = sepiaGreen;

            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally 水平反射影像
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++) // 寬度執行半邊就好 全部執行會再交換回去
        {
            RGBTRIPLE tmp = image[i][j]; // 把值放進tmp
            image[i][j] = image[i][width - 1 - j]; // 原本的位置代入新的值
            image[i][width - 1 - j] = tmp; // 新的位置空了 放進tmp的值
        }
    }
    return;
}

// Blur image 模糊影像
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width]; // 建立一個副本 避免修改後的影響下一個
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j]; // 把值複製過去copy
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumRed = 0, sumGreen = 0, sumBlue = 0;
            int count = 0;
            for (int di = -1; di < 2; di++) // 循環影格的周圍九宮格 是否為負 或 超出尺寸
            {
                for (int dj = -1; dj < 2; dj++)
                {
                    int ni = i + di;
                    int nj = j + dj;
                    if (ni >= 0 && ni < height && nj >= 0 && nj < width)
                    {
                        sumRed += copy[ni][nj].rgbtRed;
                        sumGreen += copy[ni][nj].rgbtGreen;
                        sumBlue += copy[ni][nj].rgbtBlue;
                        count++;
                    }
                }
            }
            image[i][j].rgbtRed = round((float)sumRed / count);
            image[i][j].rgbtGreen = round((float)sumGreen / count);
            image[i][j].rgbtBlue = round((float)sumBlue / count);
        }
    }
    return;
}
