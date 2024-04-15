-- Average rating of movies from 2012
-- SELECT ROUND(AVG(rating), 2)
SELECT AVG(rating)
FROM ratings
WHERE movie_id IN
(
    SELECT id
    FROM movies
    WHERE year = 2012
);
