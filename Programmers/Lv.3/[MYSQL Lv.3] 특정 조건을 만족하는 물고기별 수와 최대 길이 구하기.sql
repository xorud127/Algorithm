with fish as (
select ID, FISH_TYPE, if(LENGTH is null, 10, LENGTH) as LENGTH
from FISH_INFO
)

select count(*) as FISH_COUNT,max(LENGTH) as MAX_LENGTH , FISH_TYPE
from fish
where FISH_TYPE in (
    select FISH_TYPE
    from fish
    group by FISH_TYPE having avg(LENGTH) >= 33)
group by FISH_TYPE
order by FISH_TYPE
