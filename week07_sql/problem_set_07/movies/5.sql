-- The Harry Potter movies
SELECT title, year
FROM movies
WHERE title LIKE 'Harry Potter%'
ORDER BY year;
