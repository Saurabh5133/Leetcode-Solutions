# Write your MySQL query statement below
WITH tbl AS
(
    SELECT 
        person_name,
        turn,
        SUM(weight) OVER(ORDER BY turn) as c_sum
    FROM Queue

)
SELECT 
    person_name
FROM tbl
WHERE c_sum <= 1000
ORDER BY c_sum DESC
LIMIT 1