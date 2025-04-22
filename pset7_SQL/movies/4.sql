-- write a SQL query to determine the number of movies with an IMDb rating of 10.0.
-- 查詢 IMDb 評分為 10.0 的電影數量
SELECT COUNT(*)
  FROM ratings
 WHERE rating = '10.0';
