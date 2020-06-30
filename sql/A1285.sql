# Write your MySQL query statement below


-- select p.ai, q.ai from () as p right join (select a.log_id as ai from Logs as a where (select min(log_id) from Logs where log_id > a.log_id) != a.log_id + 1 or a.log_id = (select max(log_id) from Logs)) as q on p.ai <= q.ai ;

select p.ai start_id, q.ai end_id from (select (@n := @n + 1) as id, a.log_id as ai from Logs as a, (select @n := 0)b where (select max(log_id) from Logs where log_id < a.log_id) != a.log_id - 1 or a.log_id = (select min(log_id) from Logs)) as p left join (select (@x := @x + 1) as id, a.log_id as ai from Logs as a, (select @x := 0) b where (select min(log_id) from Logs where log_id > a.log_id) != a.log_id + 1 or a.log_id = (select max(log_id) from Logs)) as q on p.id = q.id;




