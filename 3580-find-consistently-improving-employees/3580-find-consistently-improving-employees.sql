WITH ranked AS(
    SELECT 
        e.employee_id as employee_id,
        e.name as name,
        r.rating as rating,
        ROW_NUMBER() OVER(PARTITION BY e.employee_id ORDER BY r.review_date DESC) as ranking
    FROM employees e
    LEFT JOIN performance_reviews r
    ON e.employee_id = r.employee_id
),
topRanked AS(
    SELECT
        employee_id,
        name,
        rating,
        ranking
    FROM ranked
    WHERE ranking <= 3
)
SELECT employee_id, name,
    (
        SUM(IF(ranking = 1, rating, 0)) -
        SUM(IF(ranking = 3, rating, 0))
    ) AS improvement_score
FROM topRanked
GROUP BY employee_id, name
HAVING COUNT(rating) >= 3
    AND SUM(IF(ranking=1, rating, 0)) > SUM(IF(ranking=2, rating, 0))
    AND SUM(IF(ranking=2, rating, 0)) > SUM(IF(ranking=3, rating, 0))
ORDER BY improvement_score DESC, name ASC;