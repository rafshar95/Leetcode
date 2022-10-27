# Write your MySQL query statement below


SELECT Person.FirstName, Person.LastName, Address.City, Address.STATE
FROM Person
LEFT JOIN Address
ON Person.personId = Address.personId;
