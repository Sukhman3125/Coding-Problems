SELECT
    PP1.product_id as product1_id,
    PP2.product_id as product2_id,
    PI1.category as product1_category,
    PI2.category as product2_category,
    COUNT(PP1.user_id) as customer_count
FROM
    ProductPurchases as PP1
    JOIN ProductPurchases as PP2
    ON PP1.user_id = PP2.user_id
LEFT JOIN
    ProductInfo as PI1
    ON PI1.product_id = PP1.product_id
LEFT JOIN
    ProductInfo as PI2
    ON PI2.product_id = PP2.product_id
WHERE PP1.product_id < PP2.product_id
GROUP BY PP1.product_id, PP2.product_id
HAVING customer_count >= 3
ORDER BY customer_count DESC,product1_id,product2_id