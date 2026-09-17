WITH b AS (
    SELECT *,
        ROW_NUMBER() OVER(PARTITION BY student_id, subject ORDER BY session_date) AS ranking,
        DATEDIFF(session_date, LAG(session_date) OVER(PARTITION BY student_id ORDER BY session_date)) AS conse 
    FROM study_sessions
),
rule1 AS (
    SELECT *, COUNT(DISTINCT subject) AS cycle_length,
        SUM(hours_studied) AS total_study_hours 
    FROM b 
    GROUP BY student_id
    HAVING MAX(conse) <=2 
        AND COUNT(session_id) >=6 
        AND COUNT(DISTINCT subject) >=3
),
rule2 AS(
    SELECT student_id, ranking, 
        group_concat(subject ORDER BY session_date) AS subs 
    FROM b 
    GROUP BY student_id, ranking
)
SELECT s.*, cycle_length, total_study_hours 
FROM rule1 
JOIN students s 
ON s.student_id = rule1.student_id
WHERE EXISTS (
    SELECT 1 
    FROM rule2 
    WHERE rule1.student_id = student_id 
    GROUP BY student_id, subs 
    HAVING COUNT(*) >=2
    )
ORDER BY cycle_length DESC, total_study_hours DESC