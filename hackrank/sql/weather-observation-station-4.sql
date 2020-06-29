/*
Enter your query here.
*/

select count(*) - (select count(distinct CITY) from STATION) from STATION;