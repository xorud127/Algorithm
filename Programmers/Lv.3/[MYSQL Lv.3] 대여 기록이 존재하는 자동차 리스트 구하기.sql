SELECT distinct h.CAR_ID
from CAR_RENTAL_COMPANY_RENTAL_HISTORY h join CAR_RENTAL_COMPANY_CAR c on h.CAR_ID = c.CAR_ID
where c.CAR_TYPE = "세단" and month(h.START_DATE) = 10
order by h.CAR_ID desc
