select count(TIME) as FISH_COUNT, month(TIME) as MONTH
from FISH_INFO
group by month(TIME) having count(TIME) > 0
order by month(TIME)
