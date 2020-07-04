# Write your MySQL query statement below

select a.project_id, a.employee_id from Project as a, (select a.ap as aap, max(a.be) as abe from (select a.project_id as ap, b.experience_years as be from Project as a left join Employee as b on a.employee_id = b.employee_id) as a group by a.ap) as b, Employee as c where a.project_id = b.aap and c.employee_id = a.employee_id and c.experience_years = b.abe;