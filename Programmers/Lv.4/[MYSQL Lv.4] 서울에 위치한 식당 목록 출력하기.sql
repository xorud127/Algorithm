SELECT i.REST_ID, i.REST_NAME, i.FOOD_TYPE, (i.FAVORITES) as FAVORITES, i.ADDRESS, round(avg(r.REVIEW_SCORE), 2) as SCORE
from REST_INFO i join REST_REVIEW r on i.REST_ID = r.REST_ID
where left(i.ADDRESS, 2) = "서울"
group by i.REST_ID
order by round(avg(r.REVIEW_SCORE), 2) desc, (i.FAVORITES) desc 
