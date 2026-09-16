WITH cte AS(
    SELECT
        user_id,
        plan_name,
        event_date,
        event_type,
        monthly_amount,
        ROW_NUMBER() OVER(PARTITION BY user_id ORDER BY event_date ASC) AS earliest,
        ROW_NUMBER() OVER(PARTITION BY user_id ORDER BY event_date DESC) AS latest,
        MAX(monthly_amount) OVER (PARTITION BY user_id) AS max_amount,

        MAX(IF(event_type = 'downgrade', 1, 0)) OVER (PARTITION BY user_id) AS has_downgrade
    FROM subscription_events
)
SELECT 
    user_id,
    MAX(IF(latest=1,plan_name, NULL)) AS current_plan,
    SUM(IF(latest=1,monthly_amount,0)) AS current_monthly_amount,
    MAX(max_amount) AS max_historical_amount,
    DATEDIFF(
        MAX(IF(latest = 1,event_date,NULL)),
        MAX(IF(earliest = 1,event_date,NULL))
    ) AS days_as_subscriber
FROM cte
GROUP BY user_id, has_downgrade
HAVING MAX(IF(latest = 1,event_type, NULL)) <> 'cancel'
    AND has_downgrade = 1
    AND current_monthly_amount < 0.5 * max_historical_amount
    AND days_as_subscriber >= 60
ORDER BY days_as_subscriber DESC, user_id ASC;