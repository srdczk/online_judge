# Write your MySQL query statement below

# low efficient
# select a.player_id, a.event_date, (select sum(games_played) from Activity where player_id = a.player_id and event_date <= a.event_date) as games_played_so_far from Activity as a;

select x.player_id, x.event_date, sum(y.games_played) as games_played_so_far from Activity as x, Activity as y where x.player_id = y.player_id and y.event_date <= x.event_date group by x.player_id, x.event_date;