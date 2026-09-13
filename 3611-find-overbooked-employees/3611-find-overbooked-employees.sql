SELECT
    employee_id,
    employee_name,
    department,
    SUM(weekly_hours > 20) AS meeting_heavy_weeks
FROM (
    SELECT
        e.employee_id,
        e.employee_name,
        e.department,
        YEARWEEK(m.meeting_date , 1) AS week,
        SUM(m.duration_hours) AS weekly_hours
    FROM employees e
    JOIN meetings m
        ON e.employee_id = m.employee_id
    GROUP BY
        e.employee_id,
        e.employee_name,
        e.department,
        YEARWEEK(m.meeting_date , 1)
) t
GROUP BY
    employee_id,
    employee_name,
    department
HAVING SUM(weekly_hours > 20) >= 2
ORDER BY meeting_heavy_weeks DESC, employee_name ASC;