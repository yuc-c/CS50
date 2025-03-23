#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i 第i個投票者 心目中順序
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates 候選人數組 最多9組
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false; // 淘汰為 true
    }
    // 幾個投票人 最多100人
    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes 有i個投票人 每個投票人都會有j個順位(候選人)
    for (int i = 0; i < voter_count; i++)
    {
        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid 第i個投票人,投的第j個順序的名字,有沒有這位候選人
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists 繼續選直到產生獲勝
    while (true)
    {
        // Calculate votes given remaining candidates 根據剩餘候選人計算選票
        tabulate();

        // Check if election has been won 檢查是否獲勝
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates 淘汰墊底候選人
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins 如果打平則雙方都贏
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            return 0;
        }

        // Eliminate anyone with minimum number of votes 淘汰票數最少的人
        eliminate(min);

        // Reset vote counts back to zero 將投票數重設為零
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid 如果投票有效，記錄偏好
bool vote(int voter, int rank, string name)
{
    // 循環候選人的名字  若有，則記錄 第voter個投票人的第rank順位為name
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name,name) == 0)
        {
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates 統計淘汰最少票數的人 要找最小值
void tabulate(void)
{
    // 要先計票
    // check 每個人的第一順位有沒有被淘汰 沒有則第一順位+1分 若淘汰則第二順位+1分
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (!candidates[preferences[i][j]].eliminated)
            {
                candidates[preferences[i][j]].votes++;
                break;
            }
        }

    }
    return;
}

// Print the winner of the election, if there is one 列印選舉獲勝者（如果有）
bool print_winner(void)
{
    // 循環每一個候選人的票數，若過半則打印獲勝者
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > (voter_count / 2))
        {
            printf("%s\n",candidates[i].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has 回報剩餘候選人的最低得票數
int find_min(void)
{
    // 循環每個候選人 未淘汰 的 最低票數
    int min = voter_count;
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes < min)
        {
            min = candidates[i].votes;
        }
    }
    return min;
}

// Return true if the election is tied between all candidates, false otherwise 如果所有候選人的選舉結果相同，則傳回 true，否則傳回 false
bool is_tie(int min)
{
    // 循環每個候選人 若未淘汰且分數不為min 傳回false ，反之均為min 則傳回true
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes != min)
        {
            return false;
        }
    }
    return true;
}

// Eliminate the candidate (or candidates) in last place 淘汰排名最後的候選人
void eliminate(int min)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false && candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}
