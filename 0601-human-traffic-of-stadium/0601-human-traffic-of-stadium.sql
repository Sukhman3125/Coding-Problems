SELECT s.id, s.visit_date, s.people
FROM Stadium s
LEFT JOIN Stadium prev
ON prev.id = s.id-1
LEFT JOIN Stadium prevPrev
ON prevPrev.id = s.id-2
LEFT JOIN Stadium next
ON next.id = s.id+1
LEFT JOIN Stadium nextNext
ON nextNext.id = s.id+2
WHERE   s.people >= 100
    AND 
    (
        (prev.people >= 100 AND
        prevPrev.people >=100) 
        OR
        (next.people >= 100 AND
        nextNext.people >=100)
        OR
        (prev.people >= 100 AND
        next.people >= 100)
    )
ORDER BY visit_date ASC;