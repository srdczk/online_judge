# Write your MySQL query statement below

select a.id, a.year, if(b.npv is null, 0, b.npv) as npv from Queries as a left join NPV as b on a.id = b.id and a.year = b.year;