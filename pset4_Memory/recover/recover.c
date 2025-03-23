#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 恢復 JPG檔

int main(int argc, char *argv[])
{
    // Accept a single command-line argument 接受單一命令列參數
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card 開啟記憶卡
    FILE *card = fopen(argv[1], "r");

    if (card == NULL)
    {
        printf("Could not open file\n");
        return 2;
    }

    // Create a buffer for a block of data 建立緩衝區
    uint8_t buffer[512];
    char filename[8]; // 檔案名稱為八個字元 "###.jpg" 7+1個\0
    int img_count = 0; // 循環陸續命名檔名
    FILE *img = NULL;

    // While there's still data left to read from the memory card 當記憶卡中仍有資料需要讀取時
    while (fread(buffer, 1, 512, card) == 512)
    {
        // if 偵測到新的圖片
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if(img != NULL) // 已經有打開就關掉
            {
                fclose(img);
            }

            sprintf(filename, "%03i.jpg", img_count); // 建立檔名
            img = fopen(filename, "w"); // 開啟檔案
            fwrite(buffer, 1, 512, img); // 寫入圖片
            img_count++;
        }
        else // 沒有偵測到新的圖片
        {
            if (img != NULL) // 如果不為NULL 則繼續寫入
            {
                fwrite(buffer, 1, 512, img);
            }
        }
    }

    fclose(img);
    fclose(card);
    return 0;
}
