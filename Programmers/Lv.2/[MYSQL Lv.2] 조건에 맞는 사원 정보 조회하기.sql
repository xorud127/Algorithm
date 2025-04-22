with sum_score as (
select EMP_NO, sum(SCORE) as total
from HR_GRADE
group by EMP_NO
order by total desc
limit 1)

SELECT S.total as SCORE, E.EMP_NO, E.EMP_NAME, E.POSITION, E.EMAIL
FROM HR_EMPLOYEES E
JOIN sum_score S ON E.EMP_NO = S.EMP_NO
