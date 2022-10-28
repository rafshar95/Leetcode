# Write your MySQL query statement below
SELECT worker.name as Employee
FROM Employee worker
WHERE worker.salary > (SELECT manager.salary FROM Employee manager WHERE manager.id = worker.managerId)
