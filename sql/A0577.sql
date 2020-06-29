# Write your MySQL query statement below

# not efficient
select a.name, b.bonus from (select empId, name from Employee where empId not in (select empId from Bonus where bonus >= 1000)) as a left join Bonus as b on a.empId = b.empId;

