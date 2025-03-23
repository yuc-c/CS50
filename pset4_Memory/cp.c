#include <stdio.h>
#include <stdint.h>

// 透過輸入和編寫 複製程式

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    FILE *src = fopen(argv[1], "rb"); // r (read mode 閱讀模式)
    FILE *dst = fopen(argv[2], "wb"); // w (write mode 寫入模式)

    BYTE b; // 給一個類型為byte的變量

    while (fread(&b, sizeof(b), 1, src) != 0)
    {
        fwrite(&b, sizeof(b), 1 ,dst);
    }

    fclose(dst);
    fclose(src);
}
