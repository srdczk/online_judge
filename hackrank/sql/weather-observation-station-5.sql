/*
Enter your query here.
*/

select CITY, length(CITY) from STATION where CITY = (select CITY from STATION order by length(CITY) asc, CITY asc limit 0, 1) or CITY = (select CITY from STATION order by length(CITY) desc, CITY asc limit 0, 1) order by CITY asc;