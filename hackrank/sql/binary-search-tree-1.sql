/*
Enter your query here.
*/

select  
b.N, if (b.P, if ((select count(*) from BST where P = b.N) = 0, 'Leaf', 'Inner'), 'Root') from BST as b order by b.N asc;