# Write your MySQL query statement below


-- select a.gender, a.day, sum(b.score_points) from Scores as a left join Scores as b on b.gender = a.gender and b.day <= a.day order by a.gender, a.day;

select a.gender, a.day, (select sum(score_points) from Scores where day <= a.day and gender = a.gender) as total from Scores as a  order by a.gender, a.day;