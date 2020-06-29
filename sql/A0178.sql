# Write your MySQL query statement below

# inefficient
select a.Score as 'Score', (select count(distinct Score) from Scores where Score >= a.Score) as 'Rank' from Scores as a order by a.Score desc;

# window function

# select Score, dense_rank() over(order by Score desc) as 'Rank' from Scores;
