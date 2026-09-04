Select ROUND(
    COUNT(DISTINCT b.player_id)/ COUNT(DISTINCT a.player_id)
, 2) as fraction
From (
    Select player_id, MIN(event_date) as first_date
    From Activity
    Group By player_id
    ) a
Left Join Activity b
On a.player_id = b.player_id
    AND b.event_date = a.first_date + INTERVAL 1 day;