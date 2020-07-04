# Write your MySQL query statement below




select a.p as bin, if(b.c is null, 0, b.c) as total from (select '[0-5>' as p union select '[5-10>' as p union select '[10-15>' as p union select '15 or more' as p) as a left join (select a.d, count(a.session_id) c from (select session_id, if (duration < 300, '[0-5>', if (duration < 600, '[5-10>', if (duration < 900, '[10-15>', '15 or more'))) as d from Sessions) as a group by a.d) as b on a.p = b.d;
