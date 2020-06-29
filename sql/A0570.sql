# Write your MySQL query statement below


select Name from Employee where Id in (select ManagerId from Employee group by ManagerId having count(*) >= 5);