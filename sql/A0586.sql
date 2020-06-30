# Write your MySQL query statement below



select a.a as customer_number from (select customer_number as a, count(*) as b from orders group by customer_number) as a order by a.b desc limit 0, 1;