with s as
(SELECT *
from FIRST_HALF
union all
select *
from JULY
)

select FLAVOR
from s
group by FLAVOR
order by sum(TOTAL_ORDER) desc
limit 3
