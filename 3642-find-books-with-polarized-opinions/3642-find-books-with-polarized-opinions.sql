SELECT
    b.book_id as book_id,
    b.title as title,
    b.author as author,
    b.genre as genre,
    b.pages as pages,
    MAX(r.session_rating) - MIN(r.session_rating) as rating_spread,
    ROUND(
        SUM(IF(r.session_rating <= 2 OR r.session_rating >= 4, 1, 0)) /
        COUNT(r.session_rating)
    ,2) as polarization_score
FROM books b
LEFT JOIN reading_sessions r
ON b.book_id = r.book_id
GROUP BY b.book_id, b.title, b.author, b.genre, b.pages
HAVING COUNT(r.session_rating) >= 5
    AND polarization_score >= 0.6
    AND SUM(IF(r.session_rating <= 2, 1, 0)) > 0
    AND SUM(IF(r.session_rating >= 4, 1, 0)) > 0
ORDER BY polarization_score DESC, title DESC
