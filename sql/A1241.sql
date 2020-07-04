# Write your MySQL query statement below


-- ;
-- (select sub_id );

select a.sub_id as post_id, (select count(distinct sub_id) from Submissions where parent_id = a.sub_id) as number_of_comments from Submissions as a where a.parent_id is null group by a.sub_id order by post_id;