-- write a SQL query to list the names of all people who have directed a movie that received a rating of at least 9.0.
-- 列出執導過至少獲得 9.0 評分的電影的所有人員的姓名
SELECT name
  FROM directors
  JOIN ratings ON directors.movie_id = ratings.movie_id
  JOIN people ON directors.person_id = people.id
 WHERE rating >= 9.0
 GROUP BY name;
