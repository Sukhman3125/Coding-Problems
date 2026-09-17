WITH RECURSIVE split AS (
    SELECT
        content_id,
        SUBSTRING_INDEX(content_text, ' ', 1) AS word,
        CASE WHEN LOCATE(' ', content_text) > 0
             THEN SUBSTRING(content_text, LOCATE(' ', content_text) + 1) END AS rest,
        1 AS word_num
    FROM user_content

    UNION ALL

    SELECT
        content_id,
        SUBSTRING_INDEX(rest, ' ', 1),
        CASE WHEN LOCATE(' ', rest) > 0
             THEN SUBSTRING(rest, LOCATE(' ', rest) + 1) END,
        word_num + 1
    FROM split
    WHERE rest IS NOT NULL
),

classified AS (
    SELECT content_id, word_num, word,
        CASE
            WHEN word REGEXP '^[A-Za-z]+(-[A-Za-z]+)+$' THEN 'hyphen'
            WHEN LEFT(word, 1) REGEXP '^[A-Za-z]$'      THEN 'normal'
            ELSE 'asis'
        END AS kind
    FROM split
),

chars AS (
    SELECT content_id, word_num, word, 1 AS pos,
           UPPER(SUBSTRING(word, 1, 1)) AS ch
    FROM classified
    WHERE kind = 'hyphen'

    UNION ALL

    SELECT c.content_id, c.word_num, c.word, c.pos + 1,
           CASE WHEN SUBSTRING(c.word, c.pos, 1) = '-'
                THEN UPPER(SUBSTRING(c.word, c.pos + 1, 1))
                ELSE LOWER(SUBSTRING(c.word, c.pos + 1, 1))
           END
    FROM chars c
    WHERE c.pos < LENGTH(c.word)
),

hyphen_done AS (
    SELECT content_id, word_num,
           GROUP_CONCAT(ch ORDER BY pos SEPARATOR '') AS converted_word
    FROM chars
    GROUP BY content_id, word_num
)

SELECT
    u.content_id,
    u.content_text AS original_text,
    GROUP_CONCAT(
        CASE c.kind
            WHEN 'hyphen' THEN h.converted_word
            WHEN 'normal' THEN CONCAT(UPPER(LEFT(c.word, 1)), LOWER(SUBSTRING(c.word, 2)))
            ELSE c.word
        END
        ORDER BY c.word_num SEPARATOR ' '
    ) AS converted_text
FROM user_content u
JOIN classified c ON c.content_id = u.content_id
LEFT JOIN hyphen_done h
       ON h.content_id = c.content_id AND h.word_num = c.word_num
GROUP BY u.content_id, u.content_text;