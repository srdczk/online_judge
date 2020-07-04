# Write your MySQL query statement below


select a.extra as report_reason, count(a.extra) as report_count from (select extra from Actions where action = 'report' and action_date = '2019-07-04' group by post_id, extra) as a group by a.extra;
