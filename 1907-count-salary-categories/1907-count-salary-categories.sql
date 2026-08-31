# Write your MySQL query statement below
WITH tbl AS
(
    SELECT 
    account_id, income, 
    CASE
        WHEN income<20000 THEN 'Low Salary'
        WHEN income <=50000 THEN 'Average Salary'
        ELSE 'High Salary'
    END as category
    FROM Accounts
),
categories AS
(
    SELECT 'Low Salary' as category
    UNION ALL
    SELECT 'Average Salary'
    UNION ALL
    SELECT 'High Salary'

)
SELECT 
    c.category, COUNT(t.account_id) as accounts_count
FROM categories c
LEFT JOIN tbl t
ON c.category = t.category
GROUP BY c.category

