with history as (
    select CAR_ID, 
           sum(case when (start_date <= '2022-11-30' and end_date >= '2022-11-01') then 1 else 0 end) as tf
    from CAR_RENTAL_COMPANY_RENTAL_HISTORY
    group by CAR_ID
), discount as (
    select *
    from CAR_RENTAL_COMPANY_DISCOUNT_PLAN
    where (CAR_TYPE = "세단" or CAR_TYPE = "SUV") and DURATION_TYPE = "30일 이상"
)

select h.car_id, c.car_type, floor(30 * c.DAILY_FEE * (1-d.discount_rate*0.01)) as fee
from history h join CAR_RENTAL_COMPANY_CAR c on c.car_id = h.car_id join discount d on d.CAR_TYPE = c.CAR_TYPE
where h.tf = 0 and floor(30 * c.DAILY_FEE * (1-d.discount_rate*0.01)) between 500000 and 2000000
order by fee desc, car_type, car_id desc
