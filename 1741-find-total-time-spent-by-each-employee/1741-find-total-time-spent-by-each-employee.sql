# Write your MySQL query statement below
SELECT day, emp_id, SUM(tt) AS total_time
FROM
(
    SELECT  event_day AS day, emp_id, out_time-in_time AS tt
    FROM Employees
) AS tbl
GROUP BY day, emp_id
ORDER BY day