#include <stdio.h>
#include <stdlib.h>

// malloc(size) 提供內存(可能會有殘值) realloc(*ptr,new_size) 調整內存大小 free(*ptr)釋放內存

int main(void)
{
    int *list = malloc(3 * sizeof(int)); // 分配 3 個 int 內存空間
    if (list == NULL)
    {
        return 1;
    }

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // Time passes
    int *tmp = realloc(list, 4 * sizeof(int)); // 調整 list 內存大小
    if (tmp == NULL)
    {
        free(list);
        return 1;
    }
    /* // 因使用realloc 故不需要這個
    for (int i = 0; i < 3; i++)
    {
        tmp[i] = list[i];
    }
    */

    tmp[3] = 4;

    free(list);

    list = tmp; // 取代為新的

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    // Time passes
    free(list);
    return 0;
}
