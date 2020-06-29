/*
Enter your query here.
*/

select concat(Name,'(', substr(Occupation, 1, 1), ')') from OCCUPATIONS order by Name asc;

select 'There are a total of ', count(*) as c, concat(' ', lower(Occupation), 's.') from OCCUPATIONS group by Occupation order by c asc, Occupation asc; 