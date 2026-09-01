# Write your MySQL query statement below
WITH tbl AS
(
    SELECT 
        class, COUNT(*) as num
    FROM Courses
    GROUP BY class
)
SELECT class
FROM tbl 
WHERE num >= 5