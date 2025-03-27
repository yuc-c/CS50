// Simulate genetic inheritance of blood type 作業 模擬血型的基因遺傳 
#define _DEFAULT_SOURCE
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 每個人都有兩個父母和兩個等位基因
typedef struct person
{
    struct person *parents[2];
    char alleles[2];
} person;

const int GENERATIONS = 3;
const int INDENT_LENGTH = 4;

person *create_family(int generations);
void print_family(person *p, int generation);
void free_family(person *p);
char random_allele();

int main(void)
{
    // 種子隨機數產生器
    srandom(time(0));

    // 創造一個三代同堂的新家庭
    person *p = create_family(GENERATIONS);

    // 列印血型家族樹
    print_family(p, 0);

    // 釋放記憶體
    free_family(p);
}

// 建立個體
person *create_family(int generations)
{
    // 分配內存
    person *new_person = malloc(sizeof(person));

    // 若有超過一代
    if (generations > 1)
    {
        // 建立父母並讓generations-1
        person *parent0 = create_family(generations - 1);
        person *parent1 = create_family(generations - 1);

        // 把建立的存入parents陣列
        new_person->parents[0] = parent0;
        new_person->parents[1] = parent1;

        // 從父母隨機各挑選一個基因
        new_person->alleles[0] = parent0->alleles[random() % 2];
        new_person->alleles[1] = parent1->alleles[random() % 2];
    }

    // 沒有父母
    else
    {
        // 指標設為NULL
        new_person->parents[0] = NULL;
        new_person->parents[1] = NULL;

        // 隨機基因
        new_person->alleles[0] = random_allele();
        new_person->alleles[1] = random_allele();
    }

    return new_person;
}

// 釋放內存
void free_family(person *p)
{
    if (p == NULL)
    {
        return;
    }

    free_family(p->parents[0]);
    free_family(p->parents[1]);

    free(p);
}

// Print 家庭成員跟基因
void print_family(person *p, int generation)
{
    if (p == NULL)
    {
        return;
    }

    // Print 縮排
    for (int i = 0; i < generation * INDENT_LENGTH; i++)
    {
        printf(" ");
    }

    // Print person
    if (generation == 0)
    {
        printf("Child (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }
    else if (generation == 1)
    {
        printf("Parent (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }
    else
    {
        for (int i = 0; i < generation - 2; i++)
        {
            printf("Great-");
        }
        printf("Grandparent (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }

    // Print 當前世代父母
    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
}

// 隨機血型基因
char random_allele()
{
    int r = random() % 3;
    if (r == 0)
    {
        return 'A';
    }
    else if (r == 1)
    {
        return 'B';
    }
    else
    {
        return 'O';
    }
}
