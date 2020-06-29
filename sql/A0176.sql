# Write your MySQL query statement below

# personal solution, inefficient
# select max(Salary) as SecondHighestSalary from Employee where Salary != (select max(Salary) from Employee);

# distinct, limit and so on
# 返回 0 条记录 和 返回null 值的区别
#(wrong) select distinct Salary from Employee order by Salary desc limit 1, 1;

select (select distinct Salary from Employee order by Salary desc limit 1, 1) as SecondHighestSalary;

# vselect ifnull((select distinct Salary from Employee order by Salary desc limit 1, 1), null) as SecondHighestSalary;