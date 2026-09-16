SELECT 
    ip,
    COUNT(*) AS invalid_count
FROM logs
WHERE ip NOT REGEXP '^[0-9]+\\.[0-9]+\\.[0-9]+\\.[0-9]+$' OR 
    ip REGEXP '(^|\\.)0[0-9]' OR 
    CAST(SUBSTRING_INDEX(ip, '.', 1) AS UNSIGNED) > 255 OR 
    CAST(SUBSTRING_INDEX(SUBSTRING_INDEX(ip, '.', 2), '.', -1) AS UNSIGNED) > 255 OR 
    CAST(SUBSTRING_INDEX(SUBSTRING_INDEX(ip, '.', 3), '.', -1) AS UNSIGNED) > 255 OR 
    CAST(SUBSTRING_INDEX(ip, '.', -1) AS UNSIGNED) > 255
GROUP BY ip
ORDER BY invalid_count DESC, ip DESC;