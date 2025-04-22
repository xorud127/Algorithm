select concat(FLOOR((MONTH(DIFFERENTIATION_DATE)-1)/3)+1, 'Q') as QUARTER, count(ID) as ECOLI_COUNT
from ECOLI_DATA
group by QUARTER
order by QUARTER
