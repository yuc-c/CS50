-- write a SQL query to list the names of all people who starred in a movie released in 2004, ordered by birth year.
-- 列出 2004 年上映的電影中所有主演的人員的姓名，按出生年份排序
SELECT name
  FROM movies
  JOIN stars ON movies.id = stars.movie_id
  JOIN people ON stars.person_id = people.id
 WHERE year = '2004'
 ORDER BY birth;
