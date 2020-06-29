# Write your MySQL query statement below

select distinct a.Email from Person as a, Person as b where a.Email = b.Email and a.Id != b.Id;