# Write your MySQL query statement below



# low efficient
# select seller_id from Sales group by seller_id having sum(price) = (select max(a.sp)  from (select sum(price) as sp from Sales group by seller_id) as a);

select seller_id from Sales group by seller_id having sum(price) >= all(select sum(price) from Sales group by seller_id);