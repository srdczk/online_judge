# Write your MySQL query statement below

select min(a.x - b.x) as shortest from point as a, point as b where a.x > b.x;
