# Write your MySQL query statement below


select a.sale_date, a.sold_num - b.sold_num as diff from Sales as a, Sales as b where a.sale_date = b.sale_date and a.fruit = 'apples' and b.fruit = 'oranges';