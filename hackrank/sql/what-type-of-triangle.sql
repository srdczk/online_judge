/*
Enter your query here.
*/

-- select 
--     case 
--     when a + b <= c or a + c <= b or b + c <= a then
--     'Not A Triangle'
--     when a = b and b = c then
--     'Equilateral'
--     when a = b or b = c or a = c then
--     'Isosceles'
--     else
--     'Scalene'
--     end
-- from TRIANGLES;

select if (a + b <= c or b + c <= a or a + c <= b, 'Not A Triangle', if (a = b and b = c, 'Equilateral', if (a = b or b = c or a = c, 'Isosceles', 'Scalene'))) from TRIANGLES;