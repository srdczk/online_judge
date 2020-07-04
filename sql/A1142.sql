# Write your MySQL query statement below



select if (a.c is null, 0.00, round(avg(a.c), 2)) as average_sessions_per_user from (select count(*) c from (select user_id, session_id from Activity where activity_date <= '2019-07-27' and activity_date > '2019-06-27' group by user_id, session_id) a group by a.user_id) a;