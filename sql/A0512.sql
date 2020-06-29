# Write your MySQL query statement below



select a.player_id, a.device_id from Activity as a right join (select player_id, min(event_date) as me from Activity group by player_id) as b on a.player_id = b.player_id and a.event_date = b.me;
