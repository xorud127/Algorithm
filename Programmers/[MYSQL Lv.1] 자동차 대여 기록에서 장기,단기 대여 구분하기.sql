SELECT HISTORY_ID, CAR_ID, date_format(START_DATE, "%Y-%m-%d") as START_DATE, date_format(END_DATE, "%Y-%m-%d") as END_DATE, 
(CASE
 WHEN DATEDIFF(END_DATE, START_DATE) >= 29 THEN '장기 대여'
 ELSE '단기 대여'
 END
) AS 'RENT_TYPE'
from CAR_RENTAL_COMPANY_RENTAL_HISTORY
where month(START_DATE) = 9 and year(START_DATE) = 2022
order by HISTORY_ID desc
