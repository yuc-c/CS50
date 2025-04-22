-- write a SQL query to list the titles and release years of all Harry Potter movies, in chronological order.
-- 按時間順序列出所有哈利波特電影的標題和發行年份
SELECT title, year
  FROM movies
 WHERE title
  LIKE 'Harry Potter%'
 ORDER BY year;
