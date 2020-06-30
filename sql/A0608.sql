# Write your MySQL query statement below


select a.id, if (a.p_id is null, 'Root', if ((select count(id) from tree where p_id = a.id) = 0, 'Leaf', 'Inner')) as type from tree as a;
