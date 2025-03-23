#include <cs50.h>
#include <stdio.h>
#include <string.h>

// 存儲電話簿

int main(void)
{
    FILE *file = fopen("phonebook.csv", "a"); // w 新增會覆蓋第一個; a 會新增加一個
    if (file == NULL)
    {
        return 1;
    }

    char *name = get_string("Name: ");
    char *number = get_string("Number: ");

    fprintf(file, "%s %s\n", name, number);

    fclose(file);
}
