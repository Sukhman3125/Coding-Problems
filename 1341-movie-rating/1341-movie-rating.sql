(
SELECT u.name as results
FROM Users u
LEFT JOIN MovieRating r
ON u.user_id = r.user_id
GROUP BY u.user_id
HAVING COUNT(r.movie_id) = (
    SELECT MAX(cnt)
    FROM (
        SELECT COUNT(*) AS cnt
        FROM MovieRating
        GROUP BY user_id
    ) t
)
ORDER BY u.name ASC
LIMIT 1
)
UNION ALL

(
    SELECT m.title AS results
FROM Movies m
JOIN MovieRating r
    ON m.movie_id = r.movie_id
WHERE r.created_at >= '2020-02-01'
  AND r.created_at <= '2020-02-29'
GROUP BY m.movie_id, m.title
ORDER BY AVG(r.rating) DESC, m.title ASC
LIMIT 1
)