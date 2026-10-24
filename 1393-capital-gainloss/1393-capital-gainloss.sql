# Write your MySQL query statement below
SELECT stock_name, SUM(new_price) as capital_gain_loss
FROM
(
    SELECT stock_name,
            CASE
                WHEN operation = 'Buy' THEN -price
                ELSE price
            END AS new_price
    FROM Stocks
) AS tbl
GROUP BY stock_name