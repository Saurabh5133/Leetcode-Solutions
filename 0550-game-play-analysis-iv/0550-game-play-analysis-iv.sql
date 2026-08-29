# Write your MySQL query statement below
SELECT
    ROUND(COUNT(*)/(SELECT COUNT(DISTINCT player_id) FROM Activity), 2) as fraction
FROM Activity a
JOIN
(
    SELECT 
        player_id,
        MIN(event_date) as first_date
    FROM Activity 
    GROUP BY player_id
) as tbl
ON a.player_id = tbl.player_id
WHERE DATEDIFF(a.event_date, tbl.first_date) = 1