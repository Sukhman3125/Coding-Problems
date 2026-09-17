WITH RECURSIVE level_table AS (
    SELECT employee_id, 1 AS level
    FROM employees
    WHERE manager_id IS NULL

    UNION ALL

    SELECT employees.employee_id,
        level_table.level + 1 AS level
    FROM employees
    JOIN level_table
    ON employees.manager_id = level_table.employee_id
),
all_manager_table AS (
    SELECT employee_id AS manager_id, employee_id AS emp_id
    FROM employees

    UNION ALL

    SELECT all_manager_table.manager_id, employees.employee_id
    FROM all_manager_table
    JOIN employees
    ON all_manager_table.emp_id = employees.manager_id
),
total_table AS (
    SELECT all_manager_table.manager_id,
        SUM(salary) AS budget,
        COUNT(emp_id) - 1 AS team_size
    FROM all_manager_table
    JOIN employees
    ON all_manager_table.emp_id = employees.employee_id
    GROUP BY all_manager_table.manager_id
)
SELECT l.employee_id,
    e.employee_name,
    l.level,
    t.team_size,
    t.budget
FROM level_table l
JOIN total_table t
ON l.employee_id = t.manager_id
JOIN employees e
ON e.employee_id = l.employee_id
ORDER BY l.level, t.budget DESC, e.employee_name;