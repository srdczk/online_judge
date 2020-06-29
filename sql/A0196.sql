# Write your MySQL query statement below

delete a from Person as a, Person as b where a.Email = b.Email and a.Id > b.Id;