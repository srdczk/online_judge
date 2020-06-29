# Write your MySQL query statement below

select a.id,
max(if(a.month = 'Jan', a.revenue, null)) as Jan_Revenue,
max(if(a.month = 'Feb', a.revenue, null)) as Feb_Revenue,
max(if(a.month = 'Mar', a.revenue, null)) as Mar_Revenue,
max(if(a.month = 'Apr', a.revenue, null)) as Apr_Revenue,
max(if(a.month = 'May', a.revenue, null)) as May_Revenue,
max(if(a.month = 'Jun', a.revenue, null)) as Jun_Revenue,
max(if(a.month = 'Jul', a.revenue, null)) as Jul_Revenue,
max(if(a.month = 'Aug', a.revenue, null)) as Aug_Revenue,
max(if(a.month = 'Sep', a.revenue, null)) as Sep_Revenue,
max(if(a.month = 'Oct', a.revenue, null)) as Oct_Revenue,
max(if(a.month = 'Nov', a.revenue, null)) as Nov_Revenue,
max(if(a.month = 'Dec', a.revenue, null)) as Dec_Revenue
from Department as a group by id;