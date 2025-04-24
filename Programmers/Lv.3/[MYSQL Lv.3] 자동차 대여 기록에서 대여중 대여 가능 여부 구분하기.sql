SELECT distinct CAR_ID, if (CAR_ID in (
    select CAR_ID
    from CAR_RENTAL_COMPANY_RENTAL_HISTORY
    where datediff(start_date, "2022-10-16") <= 0 and datediff(END_DATE, "2022-10-16") >= 0)
    , "대여중", "대여 가능") as AVAILABILITY
from CAR_RENTAL_COMPANY_RENTAL_HISTORY
order by CAR_ID desc
