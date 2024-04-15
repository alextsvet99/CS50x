-- Directors of films with rating 9.0 or higher
-- SELECT DISTINCT(name) FROM people WHERE id IN
SELECT name FROM people WHERE id IN
    (SELECT person_id FROM directors WHERE movie_id IN
        (SELECT movie_id FROM ratings WHERE rating >= 9.0));
