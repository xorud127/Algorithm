select b.ID, if(a.PARENT_ID is null, 0, count(a.PARENT_ID)) as CHILD_COUNT
from ECOLI_DATA a right join ECOLI_DATA b on a.PARENT_ID = b.ID
group by b.ID
order by b.ID
