# Write your MySQL query statement below
SELECT customer_number
FROM
(
    SELECT customer_number, COUNT(order_number) t_orders
    FROM Orders
    GROUP BY customer_number
    ORDER BY t_orders DESC
    LIMIT 1
) as tbl
