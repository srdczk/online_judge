# Write your MySQL query statement below


select a.Name from Candidate as a join (select CandidateId, count(*) as p from Vote group by CandidateId order by p desc limit 0, 1) as b on a.id = b.CandidateId;




