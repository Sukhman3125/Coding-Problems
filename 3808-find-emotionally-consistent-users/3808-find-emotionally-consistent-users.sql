SELECT
    r1.user_id, 
    (
        SELECT reaction
        FROM reactions r2
        WHERE r2.user_id = r1.user_id
        GROUP BY reaction
        ORDER BY COUNT(*) DESC
        LIMIT 1
    ) AS dominant_reaction,
    ROUND(
        SUM(IF(reaction = 
        (
            SELECT reaction
            FROM reactions r2
            WHERE r2.user_id = r1.user_id
            GROUP BY reaction
            ORDER BY COUNT(*) DESC
            LIMIT 1
        )
        , 1, 0))/
        COUNT(reaction)
    ,2) AS reaction_ratio
FROM reactions r1
GROUP BY r1.user_id
HAVING reaction_ratio >= 0.6
    AND COUNT(DISTINCT r1.content_id) >= 5
ORDER BY reaction_ratio DESC, user_id ASC;