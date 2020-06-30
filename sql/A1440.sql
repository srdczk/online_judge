# Write your MySQL query statement below

select a.left_operand, a.operator, a.right_operand, if(c.value > b.value and operator = '>', 'true', if(c.value < b.value and operator = '<', 'true', if(c.value = b.value and operator = '=', 'true', 'false'))) as value from Expressions as a, Variables as b, Variables as c where a.left_operand = c.name and a.right_operand = b.name;