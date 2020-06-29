/*
Enter your query here.
*/

select Name from Students where Marks > 75 order by substr(Name, -3) asc, id asc;