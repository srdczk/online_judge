# Write your MySQL query statement below

select b.stock_name, sum(a.price - b.price) as capital_gain_loss from Stocks as a, Stocks as b where a.stock_name = b.stock_name and a.operation = 'Sell' and b.operation = 'Buy' and a.operation_day = (select min(operation_day) from Stocks where operation_day > b.operation_day and stock_name = b.stock_name) group by b.stock_name;