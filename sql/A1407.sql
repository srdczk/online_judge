# Write your MySQL query statement below


select a.name, if (b.sd is null, 0, b.sd) as travelled_distance from Users as a left join (select user_id, sum(distance) as sd from Rides group by user_id) as b on a.id = b.user_id order by b.sd desc, a.name asc;