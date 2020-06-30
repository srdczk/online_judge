# Write your MySQL query statement below

select x, y, z, if(x + y <= z or y + z <= x or x + z <= y, 'No', 'Yes') as triangle from triangle;