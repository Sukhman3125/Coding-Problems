(
    SELECT "Fall" AS season, 
        p.category AS category,
        SUM(s.quantity) AS total_quantity,
        SUM(s.quantity * s.price) AS total_revenue
    FROM sales s
    LEFT JOIN products p
    ON s.product_id = p.product_id
    WHERE month(s.sale_date) IN (9,10,11)
    GROUP BY p.category
    ORDER BY total_quantity DESC, total_revenue DESC
    LIMIT 1
)

UNION

(
    SELECT "Spring" AS season, 
        p.category AS category,
        SUM(s.quantity) AS total_quantity,
        SUM(s.quantity * s.price) AS total_revenue
    FROM sales s
    LEFT JOIN products p
    ON s.product_id = p.product_id
    WHERE month(s.sale_date) IN (3,4,5)
    GROUP BY p.category
    ORDER BY total_quantity DESC, total_revenue DESC
    LIMIT 1
)

UNION

(
    SELECT "Summer" AS season, 
        p.category AS category,
        SUM(s.quantity) AS total_quantity,
        SUM(s.quantity * s.price) AS total_revenue
    FROM sales s
    LEFT JOIN products p
    ON s.product_id = p.product_id
    WHERE month(s.sale_date) IN (6,7,8)
    GROUP BY p.category
    ORDER BY total_quantity DESC, total_revenue DESC
    LIMIT 1
)

UNION

(
    SELECT "Winter" AS season, 
        p.category AS category,
        SUM(s.quantity) AS total_quantity,
        SUM(s.quantity * s.price) AS total_revenue
    FROM sales s
    LEFT JOIN products p
    ON s.product_id = p.product_id
    WHERE month(s.sale_date) IN (12,1,2)
    GROUP BY p.category
    ORDER BY total_quantity DESC, total_revenue DESC
    LIMIT 1
);