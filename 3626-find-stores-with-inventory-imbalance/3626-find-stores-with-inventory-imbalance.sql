WITH ranked as(
    SELECT
        s.store_id AS store_id,
        store_name,
        location,
        product_name,
        quantity,
        ROW_NUMBER() OVER(PARTITION BY store_name ORDER BY price ASC)  AS first,
        ROW_NUMBER() OVER(PARTITION BY store_name ORDER BY price DESC)  AS last
    FROM stores s
    JOIN inventory p
    ON s.store_id = p.store_id
)
SELECT store_id, store_name, location,
    MAX(IF(last=1, product_name, NULL)) AS most_exp_product,
    MAX(IF(first=1, product_name, NULL)) AS cheapest_product,
    ROUND(
        SUM(IF(first=1, quantity, 0))/
        SUM(IF(last=1, quantity, 0))
    ,2) AS imbalance_ratio
FROM ranked
GROUP BY store_id, store_name, location
HAVING COUNT(product_name) >= 3
    AND SUM(IF(first=1, quantity, 0)) > SUM(IF(last=1, quantity, 0))
ORDER BY imbalance_ratio DESC, store_name ASC;