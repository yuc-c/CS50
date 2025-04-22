-- write a SQL query to list the names of all people who starred in Toy Story.
-- 列出《玩具總動員》中所有主演的姓名
SELECT name
  FROM movies
  JOIN stars ON movies.id = stars.movie_id
  JOIN people ON stars.person_id = people.id
 WHERE title = 'Toy Story';
