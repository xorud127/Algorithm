select id, 
    (case when percent_rank() over (order by size_of_colony desc) < 0.25 then 'CRITICAL'
    when percent_rank() over (order by size_of_colony desc) < 0.5 then "HIGH"
    when percent_rank() over (order by size_of_colony desc) < 0.75 then "MEDIUM"
    else "LOW"
     end
    ) as COLONY_NAME
from ECOLI_DATA
order by id
