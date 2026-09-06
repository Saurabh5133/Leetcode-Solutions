# Write your MySQL query statement below
WITH tbl AS
(
    SELECT d.name AS department_name,
        e.name AS employee_name,
        e.salary,
        DENSE_RANK() OVER(PARTITION BY d.name ORDER BY e.salary DESC) as rnk
    FROM Employee e
    JOIN Department d
    ON e.departmentId = d.id
    ORDER BY d.id
)
SELECT department_name AS Department,
    employee_name AS Employee,
    salary AS Salary
FROM tbl
WHERE rnk <= 3;

