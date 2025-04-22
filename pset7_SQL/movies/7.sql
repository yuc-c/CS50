-- write a SQL query to list all movies released in 2010 and their ratings, in descending order by rating. For movies with the same rating, order them alphabetically by title.
-- 列出 2010 年上映的所有電影及其評級，按評級降序排列。對於具有相同評級的電影，按標題的字母順序排列
SELECT title, rating
  FROM movies
  JOIN ratings ON movies.id = ratings.movie_id
 WHERE year = '2010'
 ORDER BY rating DESC, title ASC;
