SELECT
    info1.category AS category1,
    info2.category AS category2,
    COUNT(DISTINCT purchase1.user_id) AS customer_count
FROM ProductInfo info1
JOIN ProductPurchases purchase1
    ON info1.product_id = purchase1.product_id
JOIN ProductPurchases purchase2
    ON purchase1.user_id = purchase2.user_id
JOIN ProductInfo info2
    ON purchase2.product_id = info2.product_id
WHERE info1.category < info2.category
GROUP BY info1.category, info2.category
HAVING COUNT(DISTINCT purchase1.user_id) >= 3
ORDER BY customer_count DESC, category1, category2;