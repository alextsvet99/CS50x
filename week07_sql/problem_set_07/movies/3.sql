-- Movies from 2018 onwards in alphabetical order
SELECT title
FROM movies
WHERE year >= 2018
ORDER BY title;
