SELECT b.author_id, a.author_name, CATEGORY, sum(b.price*s.sales) as TOTAL_SALES
from BOOK_SALES s join BOOK b on s.BOOK_ID = b.BOOK_ID join AUTHOR a on a.AUTHOR_ID = b.AUTHOR_ID
where year(SALES_DATE) = 2022 and month(SALES_DATE) = 1
group by b.author_id, CATEGORY
order by b.author_id, CATEGORY desc
