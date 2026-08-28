# Write your MySQL query statement below
WITH tbl AS
(
    SELECT 
        product_id, new_price, change_date,
        ROW_NUMBER() OVER(PARTITION BY product_id ORDER BY change_date DESC)
        as rnk
    FROM Products
    WHERE change_date <= '2019-08-16'
),
Pids AS 
(
    SELECT DISTINCT product_id
    FROM Products
)
SELECT 

    p.product_id,
    CASE
        WHEN t.rnk = 1 THEN new_price 
        ELSE 10
    END as price

FROM Pids p
LEFT JOIN tbl t
ON p.product_id = t.product_id AND t.rnk = 1;

