# Write your MySQL query statement below



select distinct buyer_id from Sales where buyer_id in (select buyer_id from Sales where product_id = (select product_id from Product where product_name = 'S8')) and buyer_id not in (select buyer_id from Sales where product_id = (select product_id from Product where product_name = 'iPhone'));