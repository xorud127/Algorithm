SELECT ORDER_ID, PRODUCT_ID, date_format(OUT_DATE, "%Y-%m-%d") as OUT_DATE, 
    (case when datediff(OUT_DATE, "2022-5-1") <= 0 then "출고완료" 
    when datediff(OUT_DATE, "2022-5-1") > 0 then "출고대기"
    else "출고미정" end) as 출고여부
from FOOD_ORDER
order by ORDER_ID
