SELECT o.PRODUCT_ID, p.PRODUCT_NAME, sum(o.AMOUNT * p.PRICE) as TOTAL_SALES
from FOOD_PRODUCT p join FOOD_ORDER o on p.PRODUCT_ID = o.PRODUCT_ID
where date_format(PRODUCE_DATE, "%Y-%m") = "2022-05"
group by PRODUCT_ID
order by sum(o.AMOUNT * p.PRICE) desc, o.PRODUCT_ID
