WITH combined AS(
    SELECT 
        d.driver_id,
        d.driver_name,
        CASE
            WHEN MONTH(t.trip_date) <= 6 THEN 0
            ELSE 1
        END AS season,
        (
            t.distance_km / t.fuel_consumed
        ) AS fuel_efficiency
    FROM drivers d
    LEFT JOIN trips t
    ON d.driver_id = t.driver_id
)
SELECT driver_id, driver_name, 
    ROUND(AVG(IF(season=0,fuel_efficiency,NULL)),2) AS first_half_avg,
    ROUND(AVG(IF(season=1,fuel_efficiency,NULL)),2) AS second_half_avg,
    ROUND(
        AVG(IF(season=1,fuel_efficiency,NULL)) -
        AVG(IF(season=0,fuel_efficiency,NULL))
    ,2) AS efficiency_improvement
FROM combined
GROUP BY driver_id, driver_name
HAVING  COUNT(IF(season=0, 1, NULL)) <> 0 AND
        COUNT(IF(season=1, 1, NULL)) <> 0 AND
        efficiency_improvement > 0
ORDER BY efficiency_improvement DESC, driver_name ASC;