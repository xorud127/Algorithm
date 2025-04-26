with history as(
    select HISTORY_ID, CAR_ID, datediff(END_DATE, START_DATE) + 1 as diff, 
        (case when datediff(END_DATE, START_DATE) + 1 >= 90 then "90일 이상"
        when datediff(END_DATE, START_DATE) + 1 >= 30 then "30일 이상"
        when datediff(END_DATE, START_DATE) + 1 >= 7 then "7일 이상"
        else "해당없음" end) as op
    from CAR_RENTAL_COMPANY_RENTAL_HISTORY
), 
discount AS (
    SELECT CAR_TYPE, DURATION_TYPE, DISCOUNT_RATE
    FROM CAR_RENTAL_COMPANY_DISCOUNT_PLAN
    WHERE CAR_TYPE = '트럭') 

select h.history_id, 
    (case when op = "해당없음" then floor(diff*DAILY_FEE)
     else floor(diff * DAILY_FEE * (1-0.01*DISCOUNT_RATE)) end
    ) as fee
from history h join CAR_RENTAL_COMPANY_CAR c on c.car_id = h.car_id left join discount d on h.op = d.DURATION_TYPE
where c.car_type = "트럭"
order by fee desc, h.history_id desc
