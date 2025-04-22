-- write a SQL query to determine the average rating of all movies released in 2012.
-- 查詢確定 2012 年上映的所有電影的平均分數
SELECT AVG(rating)
  FROM movies
  JOIN ratings
    ON movies.id = ratings.movie_id
 WHERE year = '2012';
