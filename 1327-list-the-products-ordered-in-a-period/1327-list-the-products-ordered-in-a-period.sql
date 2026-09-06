# Write your MySQL query statement below
SELECT p.product_name,
        SUM(o.unit) as unit
FROM Orders o 
LEFT JOIN Products p
ON o.product_id = p.product_id
WHERE order_date >= '2020-02-01' AND order_date < '2020-03-01'
GROUP BY o.product_id, p.product_name
HAVING SUM(o.unit) >= 100
ORDER BY o.product_id, p.product_name