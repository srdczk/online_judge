# Write your MySQL query statement below



select a.company_id, a.employee_id, a.employee_name, if(b.ms < 1000, a.salary, if(b.ms <= 10000, round(a.salary * 0.76, 0), round(a.salary * 0.51, 0))) as salary from  Salaries as a left join (select company_id, max(salary) as ms from Salaries group by company_id) as b on a.company_id = b.company_id;