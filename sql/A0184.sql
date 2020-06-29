# Write your MySQL query statement below



select distinct c.Name as Department, b.Name as Employee, b.Salary as Salary from (select max(Salary) as s, DepartmentId as d from Employee group by DepartmentId) as a, Employee as b, Department as c where a.s = b.Salary and a.d = b.DepartmentId and b.DepartmentId = c.Id;