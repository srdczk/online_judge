# Write your MySQL query statement below

select a.id as project_id from (select project_id as id, count(*) as c from Project group by project_id) as a where a.c = (select max(b.c) from (select count(*) as c from Project group by project_id) as b);
