# Write your MySQL query statement below

SELECT c1.id
FROM Weather c1, Weather c2
WHERE c1.temperature > c2.temperature AND c1.recordDate = c2.recordDate + Interval 1 Day;
