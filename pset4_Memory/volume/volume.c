// Modifies the volume of an audio file 修改音量

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// 作業 修改音量

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments 沒有輸入四個 報錯
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");  // 讀取
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w"); // 輸出
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]); // 需要調音量故將第三個命令列 轉換小數點

    // TODO: Copy header from input file to output file 將標題從輸入檔複製到輸出文件

    uint8_t header[HEADER_SIZE];
    fread(header, HEADER_SIZE, 1, input); // 讀取檔名
    fwrite(header, HEADER_SIZE, 1, output); // 寫入一個新檔名


    // TODO: Read samples from input file and write updated data to output file 從輸入文件讀取樣本並將更新的資料寫入輸出文件

    int16_t buffer;

    while (fread(&buffer, sizeof(int16_t), 1, input))
    {
        buffer *= factor; // 新的因子

        fwrite(&buffer, sizeof(int16_t), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
