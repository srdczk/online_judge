/*
Enter your query here.
*/

select distinct CITY from STATION where CITY regexp '^[^AEIOU]|[^aeiou]$';
