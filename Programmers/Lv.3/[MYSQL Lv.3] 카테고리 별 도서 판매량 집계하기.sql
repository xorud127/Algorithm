SELECT b.CATEGORY, sum(s.SALES) as TOTAL_SALES
from BOOK_SALES s join BOOK b on s.BOOK_ID = b.BOOK_ID
where date_format(s.SALES_DATE, "%Y-%m") = "2022-01"
group by b.CATEGORY
order by b.CATEGORY
