# Write your MySQL query statement below



-- select a.ad_id, if(b.bc is null, 0.00, round(b.bc * 100, 2)) as ctr from (select ad_id from Ads group by ad_id) as a left join (select a.ad_id as ai, b.c / (b.c + if(c.c, c.c, 0)) as bc from (select ad_id from Ads group by ad_id) as a, (select ad_id, count(*) as c from Ads where action = 'Clicked' group by ad_id) as b, (select ad_id, count(*) as c from Ads where action = 'Viewed' group by ad_id) as c where a.ad_id = b.ad_id and a.ad_id = c.ad_id) as b on a.ad_id = b.ai order by ctr desc, a.ad_id asc;

-- select a.ad_id as ai, b.c / (b.c + if(c.c, c.c, 0)) as bc from (select ad_id from Ads group by ad_id) as a, (select ad_id, count(*) as c from Ads where action = 'Clicked' group by ad_id) as b, (select ad_id, count(*) as c from Ads where action = 'Viewed' group by ad_id) as c where a.ad_id = b.ad_id and a.ad_id = c.ad_id;

-- select a.ad_id as ai, if(b.c is null, 0, b.c) as bc from (select ad_id from Ads group by ad_id) as a left join (select ad_id, count(*) as c from Ads where action = 'Viewed' group by ad_id) as b on b.ad_id = a.ad_id;

-- select ad_id, count(*) as c from Ads where action = 'Clicked' group by ad_id;

-- select a.ad_id as ai ai, if(b.c is null, 0, b.c) as bc from (select ad_id from Ads group by ad_id) as a left join (select ad_id, count(*) as c from Ads where action = 'Clicked' group by ad_id) as b on b.ad_id = a.ad_id;

select a.ai as ad_id, if(b.bc + a.bc = 0, 0.00, round((b.bc) / (a.bc + b.bc) * 100, 2)) as ctr from (select a.ad_id as ai, if(b.c is null, 0, b.c) as bc from (select ad_id from Ads group by ad_id) as a left join (select ad_id, count(*) as c from Ads where action = 'Viewed' group by ad_id) as b on b.ad_id = a.ad_id) as a left join (select a.ad_id as ai, if(b.c is null, 0, b.c) as bc from (select ad_id from Ads group by ad_id) as a left join (select ad_id, count(*) as c from Ads where action = 'Clicked' group by ad_id) as b on b.ad_id = a.ad_id) as b on a.ai = b.ai order by ctr desc, ad_id asc;



