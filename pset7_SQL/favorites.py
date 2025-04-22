# import csv

# with open("favorites.csv", "r") as file:
#     reader = csv.DictReader(file) # 與.reader相比 更可以列名
#     counts = {}
#     for row in reader:
#         favorite = row["language"]
#         if favorite in counts:
#             counts[favorite] += 1
#         else:
#             counts[favorite] = 1

# for favorite in sorted(counts, key = counts.get, reverse = True): # sorted() 按照方式排序
#     print(f"{favorite}: {counts[favorite]}")

# SELECT COUNT(*) FROM favorites WHERE language = '' AND problem = '';
# SELECT language, COUNT(*) (AS n) FROM favorites GROUP BY language ORDER BY language (ASC/DESC);
# 新增 INSERT INTO favorites (language, problem) VALUES( , );
# 刪除 DELETE FROM favorites WHERE Timestamp IS NULL;
# 更新 UPDATE favorites SET language = 'SQL', problem = 'Fiftyville';
# 合併 SELECT * FROM shows JOIN ratings ON shows.id = ratings.show_id WHERE rating >= 6.0 LIMT 10;
# 建立索引(更快) CREATE INDEX title_index ON shows(title);

from cs50 import SQL

db = SQL("sqlite:///favorites.db")

favorite = input("Favorite: ")

rows = db.execute("SELECT COUNT(*) AS n FROM favorites WHERE language = ?", favorite)
row = rows[0]

print(row["n"])
