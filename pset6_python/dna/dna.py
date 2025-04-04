# 作業5 DNA

import csv
import sys


def main():

    # 檢查命令列參數
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        return False

    # 讀取 DNA 資料庫
    database = []
    with open(sys.argv[1], newline='') as csvfile:
        reader = csv.DictReader(csvfile) # 把每一行轉成 dict
        for row in reader:
            for key in row:
                if key != "name":
                    row[key] = int(row[key])
            database.append(row)

    # 讀取 DNA 序列
    with open(sys.argv[2]) as file:
        dna_sequence = file.read()

    # 計算 DNA 序列中每個 STR 的最長連續重複次數
    str_list = list(database[0].keys())[1:]
    # str_list = ["AGAT", "AATG", "TATC"]

    str_counts = {}
    for str_seq in str_list:
        str_counts[str_seq] = longest_match(dna_sequence, str_seq)
    # str_count = {"AGAT" : 1, "AATG" : 1, "TATC" : 1}

    # 比對資料庫
    for person in database:
        if all(person[str_seq] == str_counts[str_seq] for str_seq in str_list):
                print(person["name"])
                return
    print("No match")


def longest_match(sequence, subsequence):
    """計算 STR 在 DNA 序列中的最長連續出現次數"""

    # 初始化
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # 檢查序列中的每個字元是否連續運行子序列
    for i in range(sequence_length):

        # 初始化
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
