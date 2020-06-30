# Write your MySQL query statement below

select distinct a.seat_id from cinema as a, cinema as b where (a.free = '1') and ((b.seat_id = a.seat_id - 1 and b.free = '1') or (b.seat_id = a.seat_id + 1 and b.free = '1'));