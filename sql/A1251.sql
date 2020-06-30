# Write your MySQL query statement below

select p.bp as product_id, round(sum(p.ab) / sum(p.bu), 2) as average_price from (select a.price * b.units as ab, b.units as bu, b.product_id as bp from Prices as a right join UnitsSold as b on a.product_id = b.product_id and b.purchase_date >= a.start_date and b.purchase_date <= a.end_date) as p group by p.bp;
