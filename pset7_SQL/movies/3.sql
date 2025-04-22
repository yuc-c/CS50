-- write a SQL query to list the titles of all movies with a release date on or after 2018, in alphabetical order.
-- 按字母順序列出上映日期在 2018 年或之後的所有電影的標題
SELECT title
  FROM movies
 WHERE year >= '2018'
 GROUP BY title
 ORDER BY title
   ASC;
