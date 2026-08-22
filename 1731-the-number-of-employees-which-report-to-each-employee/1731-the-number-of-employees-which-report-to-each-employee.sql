# Write your MySQL query statement below

SELECT
    mngr.employee_id,
    mngr.name,
    COUNT(emp.employee_id) as reports_count,
    ROUND(AVG(emp.age)) as average_age 
FROM Employees as mngr
JOIN Employees as emp
ON mngr.employee_id = emp.reports_to
GROUP BY mngr.employee_id, mngr.name
ORDER BY mngr.employee_id;
