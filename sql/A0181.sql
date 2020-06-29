# Write your MySQL query statement below

# inefficient
# select a.Name as 'Employee' from Employee as a where a.Salary > (select ifnull((select Salary from Employee where Id = a.ManagerId), null));

# where like continuity person
# select a.Name as 'Employee' from Employee as a, Employee as b where a.ManagerId = b.Id and a.Salary > b.Salary;

select a.Name as 'Employee' from Employee as a join Employee as b on a.ManagerId = b.Id and a.Salary > b.Salary;