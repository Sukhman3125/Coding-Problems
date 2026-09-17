WITH users AS (
    SELECT user_id,
           COUNT(course_id) AS course_count,
           AVG(course_rating) AS avg_rating
    FROM course_completions
    GROUP BY user_id
),
Top_Performance AS (
    SELECT *
    FROM users
    WHERE avg_rating >= 4 AND course_count >= 5
),
Second_course AS (
    SELECT course_name AS first_course,
           LEAD(course_name) OVER (PARTITION BY C.user_id ORDER BY completion_date) AS second_course    
    FROM course_completions C
    INNER JOIN Top_Performance T ON C.user_id = T.user_id
)

SELECT first_course, 
       second_course,
       COUNT(*) AS transition_count
FROM Second_course
WHERE first_course IS NOT NULL AND second_course IS NOT NULL
GROUP BY first_course, second_course
ORDER BY transition_count DESC, first_course ASC, second_course ASC;