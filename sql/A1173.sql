# Write your MySQL query statement below

select round(a.ca / b.cb * 100, 2) as  immediate_percentage from (select count(delivery_id) as ca from Delivery where order_date = customer_pref_delivery_date) as a, (select count(*) as cb from Delivery) as b;
