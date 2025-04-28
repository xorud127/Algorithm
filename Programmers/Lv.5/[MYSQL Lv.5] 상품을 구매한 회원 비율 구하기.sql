with person as (
    select count(*) as cnt
    from USER_INFO
    where year(JOINED) = "2021"
)

select year(SALES_DATE), month(SALES_DATE), count(distinct USER_ID) as PURCHASED_USERS, round(count(distinct USER_ID)/cnt, 1) as PUCHASED_RATIO
from ONLINE_SALE, person
where USER_ID in (select USER_ID
                from USER_INFO
                 where year(JOINED) = "2021")
group by year(SALES_DATE), month(SALES_DATE)
order by year(SALES_DATE), month(SALES_DATE)
