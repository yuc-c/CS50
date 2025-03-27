#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

// 列表

typedef struct node
{
    int number;
    struct node *next;
} node;

int main(void)
{
    // Memory for numbers 初始化
    node *list = NULL; // 給一個名為list變量 但不要有殘值

    // Build list
    for (int i = 0; i < 3; i++)
    {
        // Allocate node for number 分配節點數量
        node *n = malloc(sizeof(node)); // n 指向內存
        if (n == NULL)
        {
            // TODO: free any memory already malloc'd
            return 1;
        }
        n->number = get_int("Number: ");
        n->next = NULL;

        // If list is empty 明確列表是否為空
        if (list == NULL)
        {
            list = n; // 為空則設立為 n 新地址
        }

        // If number belongs at beginning of list 如果數字屬於清單開頭
        else if (n->number < list->number) // 新的指向數字 小於原本指向的
        {
            n->next = list; // 那將新的數字列為新的指向
            list = n;
        }

        // If number belongs later in list 如果數字位於清單後面
        else
        {
            // Iterate over nodes in list 迭代列表中的節點
            for (node *ptr = list; ptr != NULL; ptr = ptr->next) // 最初設為起始位置,只要指針不為空,將指針設為next
            {
                // If at end of list 列表末尾
                if (ptr->next == NULL) // 若下一個為空了 那就代表是末尾了 更改為地址n
                {
                    // Append node
                    ptr->next = n;
                    break;
                }

                // If in middle of list 如果位於清單中間
                if (n->number < ptr->next->number)
                {
                    n->next = ptr->next;
                    ptr->next = n;
                    break;
                }
            }

        }
    }

    // Time passes

    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr->number);
    }

    /* 簡潔用for
    node *ptr = list;
    while (ptr != NULL)
    {
        printf("%i\n", ptr->number);
        ptr = ptr->next;
    }
    */

    // Time passes

    node *ptr = list;
    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }

    return 0;



}
