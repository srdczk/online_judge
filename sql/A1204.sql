# Write your MySQL query statement below



select a.an as person_name from (select a.person_name an, @rk := @rk + a.weight rk from Queue a, (select @rk := 0) b order by a.turn) a where a.rk <= 1000 order by a.rk desc limit 0, 1;



-- select a.an from () a, (select max(a.rk) mr from (select a.person_name an, @rk := @rk + a.weight rk from Queue a, (select @rk := 0) b order by a.turn) a where a.rk <= 1000) b where b.mr - a.rk < 0;
