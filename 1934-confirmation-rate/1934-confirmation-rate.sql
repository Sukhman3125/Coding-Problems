SELECT s.user_id AS user_id, 
    ROUND(
        IF(COUNT(c.time_stamp) = 0, 
            0,
            SUM(IF(c.action = "confirmed", 1, 0)) / COUNT(c.time_stamp)
        )
    ,2) AS confirmation_rate
FROM Signups s
LEFT JOIN Confirmations c
ON s.user_id = c.user_id
GROUP BY user_id;