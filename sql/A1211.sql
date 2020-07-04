# Write your MySQL query statement below

-- ;
-- -- ;


select a.query_name, a.r as quality, if (round(b.c / a.c * 100, 2) is null, 0.00, round(b.c / a.c * 100, 2)) as poor_query_percentage from (select query_name, count(*) as c, round(sum(rating / position) / count(*), 2) as r from Queries group by query_name) as a left join (select query_name, count(*) as c from Queries where rating < 3  group by query_name) as b on a.query_name = b.query_name;

