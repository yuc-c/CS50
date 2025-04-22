-- write a SQL query to list the titles of the five highest rated movies (in order) that Chadwick Boseman starred in, starting with the highest rated.
-- 列出 Chadwick Boseman 主演的五部評分最高的電影的標題（按順序），從評分最高的開始
SELECT title
FROM movies
JOIN ratings ON movies.id = ratings.movie_id
JOIN stars ON movies.id = stars.movie_id
JOIN people ON stars.person_id = people.id
WHERE name = 'Chadwick Boseman'
ORDER BY rating DESC
LIMIT 5;

