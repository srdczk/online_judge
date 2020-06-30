# Write your MySQL query statement below

select a.project_id, round((select sum(experience_years) from Employee where employee_id in (select employee_id from Project where project_id = a.project_id)) / count(*), 2) as average_years from Project as a group by project_id;