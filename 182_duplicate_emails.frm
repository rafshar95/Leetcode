# Write your MySQL query statement below
WITH CTE AS
(SELECT COUNT(*) AS email_count, email
 FROM Person
 GROUP BY email)
SELECT email
FROM CTE
WHERE email_count > 1;
