-- write a SQL query to list the titles of all movies in which both Bradley Cooper and Jennifer Lawrence starred.
-- 列出 Bradley Cooper 和 Jennifer Lawrence 主演的所有電影的標題
SELECT title
  FROM movies
  JOIN stars ON movies.id = stars.movie_id
  JOIN people ON stars.person_id = people.id
 WHERE name IN ('Bradley Cooper', 'Jennifer Lawrence')
 GROUP BY title
HAVING COUNT(DISTINCT name) = 2;
-- HAVING COUNT(DISTINCT) 聚合查詢
