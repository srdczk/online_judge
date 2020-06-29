/*
Enter your query here.
*/

# round 

select round(sum(LAT_N), 2) as lat, round(sum(LONG_W), 2) as lon from STATION;