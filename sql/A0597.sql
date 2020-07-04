# Write your MySQL query statement below


select if (a.c / b.c is null, 0.00, round(a.c / b.c, 2)) as accept_rate from (select count(a.c) c from (select count(*) c from request_accepted group by requester_id, accepter_id) a) a, (select count(a.c) c from (select count(*) c from friend_request group by sender_id, send_to_id) a) b;

