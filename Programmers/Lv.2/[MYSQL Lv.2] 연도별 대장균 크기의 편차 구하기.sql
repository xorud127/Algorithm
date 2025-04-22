with max_colony as (
select year(DIFFERENTIATION_DATE) as YEAR, max(SIZE_OF_COLONY) as mx
from ECOLI_DATA
group by year(DIFFERENTIATION_DATE)
)

select year(f.DIFFERENTIATION_DATE) as YEAR, s.mx - f.SIZE_OF_COLONY as YEAR_DEV, f.ID
from ECOLI_DATA f left join max_colony s on year(f.DIFFERENTIATION_DATE) = s.YEAR
order by year(f.DIFFERENTIATION_DATE), s.mx - f.SIZE_OF_COLONY
