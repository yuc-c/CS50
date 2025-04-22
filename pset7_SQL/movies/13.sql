-- write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred.
-- 列出 Kevin Bacon 主演的電影中所有主演的姓名

/* 先列出
SELECT title
  FROM movies
  JOIN stars ON movies.id = stars.movie_id
  JOIN people ON stars.person_id = people.id
 WHERE name = 'Kevin Bacon';
-- Kevin 主演的
*/

SELECT name
FROM movies
JOIN stars ON movies.id = stars.movie_id
JOIN people ON stars.person_id = people.id
WHERE title IN (
    SELECT title
    FROM movies
    JOIN stars ON movies.id = stars.movie_id
    JOIN people ON stars.person_id = people.id
    WHERE name = 'Kevin Bacon'
 )
AND name != 'Kevin Bacon'
GROUP BY name;
