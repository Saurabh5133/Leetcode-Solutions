# Write your MySQL query statement below
WITH tbl AS
(SELECT email, COUNT(email) as EmailC
FROM Person
GROUP BY email)

SELECT email
FROM tbl
WHERE EmailC > 1;

