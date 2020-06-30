# Write your MySQL query statement below


select a.employee_id, b.ct as team_size from Employee as a left join (select team_id as t, count(team_id) as ct from Employee group by team_id) as b on a.team_id = b.t;


